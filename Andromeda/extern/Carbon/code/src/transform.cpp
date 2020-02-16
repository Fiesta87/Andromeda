#include <transform.hpp>

namespace Carbon
{
	Transform::Transform(Entity& entity, Transform* parent)
		: m_scale(Vector3::ONE)
		, m_pEntity(&entity)
		, m_pParent(parent)
		, m_bfDirty(Transform::BITFLAG_DIRTY_ALL)
	{
		if (NULL != parent)
		{
			parent->m_lpChildren.push_back(this);
		}
	}


	Transform::Transform(const Transform& other)
		: m_scale(other.m_scale)
		, m_pEntity(other.m_pEntity)
		, m_pParent(other.m_pParent)
		, m_bfDirty(m_bfDirty)
	{
	}


	Transform::~Transform()
	{
	}


	void Transform::SetPositionInLocalSpace(const Vector3& newLocalPosition)
	{
		m_position = newLocalPosition;

		SetSubHierarchyDirtyWorldTransformMarix();
	}


	Vector3 Transform::GetPositionInWorldSpace() const
	{
		Matrix3x4 mat = GetWorldTransformMatrix();

		return Vector3(mat[3], mat[7], mat[11]);
	}


	void Transform::SetPositionInWorldSpace(const Vector3& newWorldPosition)
	{
		if (NULL != m_pParent)
		{
			Matrix3x4 worldToLocal = m_pParent->GetWorldTransformMatrix().Inverse();

			m_position = m_pParent->GetWorldTransformMatrix() * (worldToLocal * newWorldPosition + Vector3(worldToLocal.m03, worldToLocal.m13, worldToLocal.m23));
		}
		else
		{
			m_position = newWorldPosition;
		}

		SetSubHierarchyDirtyWorldTransformMarix();
	}


	void Transform::SetRotationInLocalSpace(const Quaternion& newLocalRotation)
	{
		m_rotation = newLocalRotation;

		SetSubHierarchyDirty();
	}


	Quaternion Transform::GetRotationInWorldSpace() const
	{
		if (m_bfDirty & Transform::BITFLAG_DIRTY_WORLD_ROTATION)
		{
			if (nullptr != m_pParent)
				m_worldRotationCache = m_rotation * m_pParent->GetRotationInWorldSpace();
			else
				m_worldRotationCache = m_rotation;

			m_bfDirty &= ~Transform::BITFLAG_DIRTY_WORLD_ROTATION;
		}

		return m_worldRotationCache;
	}


	void Transform::SetRotationInWorldSpace(const Quaternion& newWorldRotation)
	{
		if (nullptr == m_pParent)
		{
			m_rotation = newWorldRotation;

			SetSubHierarchyDirty();

			return;
		}

		// diff * q1 = q2  --->  diff = q2 * inverse(q1)
		// local * parentWorldRotation = newWorldRotation  --->  local = newWorldRotation * inverse(parentWorldRotation)

		m_rotation = newWorldRotation * m_pParent->GetRotationInWorldSpace().Inverse();

		SetSubHierarchyDirty();
	}


	void Transform::SetScaleInLocalSpace(const Vector3& scale)
	{
		m_scale = scale;

		SetSubHierarchyDirtyWorldTransformMarix();
	}


	Vector3 Transform::GetScaleInWorldSpace() const
	{
		if (nullptr != m_pParent)
			return Vector3::HadamardProduct(m_scale, m_pParent->GetScaleInWorldSpace());
		return
			m_scale;
	}


	void Transform::SetScaleInWorldSpace(const Vector3& scale)
	{
		if (nullptr != m_pParent)
			m_scale = Vector3::HadamardDivision(scale, m_pParent->GetScaleInWorldSpace());
		else
			m_scale = scale;

		SetSubHierarchyDirtyWorldTransformMarix();
	}


	void Transform::TranslateInLocalSpace(const Vector3& translation)
	{
		m_position += translation;

		SetSubHierarchyDirtyWorldTransformMarix();
	}


	void Transform::TranslateInWorldSpace(const Vector3& translation)
	{
		if (nullptr != m_pParent)
			SetPositionInWorldSpace(GetPositionInWorldSpace() + translation);
		else
		{
			m_position += translation;
			SetSubHierarchyDirtyWorldTransformMarix();
		}
	}


	void Transform::TranslateRelativeTo(const Vector3& translation, const Transform& relativeTo)
	{
		Vector3 translationInWorldSpace = relativeTo.GetWorldTransformMatrix() * translation;

		if (nullptr != m_pParent)
			SetPositionInWorldSpace(GetPositionInWorldSpace() + translationInWorldSpace);
		else
		{
			m_position += translationInWorldSpace;
			SetSubHierarchyDirtyWorldTransformMarix();
		}
	}


	void Transform::RotateInLocalSpace(const Quaternion& rotation)
	{
		m_rotation = m_rotation * rotation;
		SetSubHierarchyDirty();
	}


	void Transform::RotateInWorldSpace(const Quaternion& rotation)
	{
		if (nullptr == m_pParent)
		{
			m_rotation = m_rotation * rotation;
			SetSubHierarchyDirty();
			return;
		}

		// rotate around World and then compare with parent rotation
		Quaternion newWorldRotation = GetRotationInWorldSpace() * rotation;

		// diff * q1 = q2  --->  diff = q2 * inverse(q1)
		// local * parentWorldRotation = newWorldRotation  --->  local = newWorldRotation * inverse(parentWorldRotation)

		m_rotation = newWorldRotation * m_pParent->GetRotationInWorldSpace().Inverse();
		SetSubHierarchyDirty();
	}


	Matrix3x4 Transform::GetLocalTransformMatrix() const
	{
		Matrix3x4 mat = m_rotation.ToMatrix();

		if (1.0f != m_scale.X)
		{
			mat[0] *= m_scale.X;
			mat[4] *= m_scale.X;
			mat[8] *= m_scale.X;
		}

		if (1.0f != m_scale.Y)
		{
			mat[1] *= m_scale.Y;
			mat[5] *= m_scale.Y;
			mat[9] *= m_scale.Y;
		}

		if (1.0f != m_scale.Z)
		{
			mat[2] *= m_scale.Z;
			mat[6] *= m_scale.Z;
			mat[10] *= m_scale.Z;
		}

		mat[3] = m_position.X;
		mat[7] = m_position.Y;
		mat[11] = m_position.Z;

		return mat;
	}


	Matrix3x4 Transform::GetWorldTransformMatrix() const
	{
		if (m_bfDirty & Transform::BITFLAG_DIRTY_WORLD_TRANSFORM_MATRIX)
		{
			if (nullptr != m_pParent)
				m_worldTransformMatrixCache = GetLocalTransformMatrix() * m_pParent->GetWorldTransformMatrix();
			else
				m_worldTransformMatrixCache = GetLocalTransformMatrix();

			m_bfDirty &= ~Transform::BITFLAG_DIRTY_WORLD_TRANSFORM_MATRIX;
		}

		return m_worldTransformMatrixCache;
	}


	Vector3 Transform::GetForward() const
	{
		if (m_bfDirty & Transform::BITFLAG_DIRTY_FORWARD)
		{
			m_forwardCache = GetRotationInWorldSpace() * Vector3::FORWARD;
			m_bfDirty &= ~Transform::BITFLAG_DIRTY_FORWARD;
		}

		return m_forwardCache;
	}


	Vector3 Transform::GetBackward() const
	{
		if (m_bfDirty & Transform::BITFLAG_DIRTY_FORWARD)
		{
			m_forwardCache = GetRotationInWorldSpace() * Vector3::FORWARD;
			m_bfDirty &= ~Transform::BITFLAG_DIRTY_FORWARD;
		}

		return -m_forwardCache;
	}


	Vector3 Transform::GetUp() const
	{
		if (m_bfDirty & Transform::BITFLAG_DIRTY_UP)
		{
			m_upCache = GetRotationInWorldSpace() * Vector3::UP;
			m_bfDirty &= ~Transform::BITFLAG_DIRTY_UP;
		}

		return m_upCache;
	}


	Vector3 Transform::GetDown() const
	{
		if (m_bfDirty & Transform::BITFLAG_DIRTY_UP)
		{
			m_upCache = GetRotationInWorldSpace() * Vector3::UP;
			m_bfDirty &= ~Transform::BITFLAG_DIRTY_UP;
		}

		return -m_upCache;
	}


	Vector3 Transform::GetRight() const
	{
		if (m_bfDirty & Transform::BITFLAG_DIRTY_RIGHT)
		{
			m_rightCache = GetRotationInWorldSpace() * Vector3::RIGHT;
			m_bfDirty &= ~Transform::BITFLAG_DIRTY_RIGHT;
		}

		return m_rightCache;
	}


	Vector3 Transform::GetLeft() const
	{
		if (m_bfDirty & Transform::BITFLAG_DIRTY_RIGHT)
		{
			m_rightCache = GetRotationInWorldSpace() * Vector3::RIGHT;
			m_bfDirty &= ~Transform::BITFLAG_DIRTY_RIGHT;
		}

		return -m_rightCache;
	}


	void Transform::SetSubHierarchyDirty()
	{
		m_bfDirty = Transform::BITFLAG_DIRTY_ALL;

		for (Transform* pChild : m_lpChildren)
		{
			pChild->SetSubHierarchyDirty();
		}
	}


	void Transform::SetSubHierarchyDirtyWorldTransformMarix()
	{
		m_bfDirty |= Transform::BITFLAG_DIRTY_WORLD_TRANSFORM_MATRIX;

		for (Transform* pChild : m_lpChildren)
		{
			pChild->SetSubHierarchyDirtyWorldTransformMarix();
		}
	}
}

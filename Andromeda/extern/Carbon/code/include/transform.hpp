#pragma once

#include <carbon.hpp>

#include <vector>

#include <vector3.hpp>
#include <matrix3x4.hpp>
#include <quaternion.hpp>


namespace Carbon
{
	class Entity;


	////////////////////////////////////////////////////////////////////////////////
	// Transform
	////////////////////////////////////////////////////////////////////////////////
	class Transform
	{
	public:
		Transform(Entity& entity, Transform* parent = nullptr);
		Transform(const Transform& other);
		~Transform();

		Entity& GetEntity() const { return *m_pEntity; }

		Entity* GetParentEntity() const { return nullptr == m_pParent ? nullptr : &m_pParent->GetEntity(); }
		Transform* GetParentTransform() const { return m_pParent; }

		const std::vector<Transform*>& GetChildrenTransform() const { return m_lpChildren; }
		Transform* GetChildTransform(int index) const { return m_lpChildren[index]; }

		/*const std::vector<Entity*>& GetChildrenEntity() const { return m_lpChildren; }
		Transform* GetChildEntity(int index) const { return m_lpChildren[index]; }*/

		const Vector3& GetPositionInLocalSpace() const { return m_position; }
		void SetPositionInLocalSpace(const Vector3& newLocalPosition);
		void SetPositionInLocalSpace(float x, float y, float z) { SetPositionInLocalSpace(Vector3(x, y, z)); }

		Vector3 GetPositionInWorldSpace() const;
		void SetPositionInWorldSpace(const Vector3& newWorldPosition);
		void SetPositionInWorldSpace(float x, float y, float z) { SetPositionInWorldSpace(Vector3(x, y, z)); }

		const Quaternion& GetRotationInLocalSpace() const { return m_rotation; }
		void SetRotationInLocalSpace(const Quaternion& newLocalRotation);

		Quaternion GetRotationInWorldSpace() const;
		void SetRotationInWorldSpace(const Quaternion& newWorldRotation);

		Vector3 GetRotationEulerAnglesRadInLocalSpace() const { return m_rotation.GetEulerAnglesRad(); }
		void SetRotationEulerAnglesRadInLocalSpace(const Vector3& eulerAngles) { SetRotationInLocalSpace(Quaternion::FromEulerAnglesRad(eulerAngles)); }
		void SetRotationEulerAnglesRadInLocalSpace(float xAngle, float yAngle, float zAngle) { SetRotationInLocalSpace(Quaternion::FromEulerAnglesRad(xAngle, yAngle, zAngle)); }

		Vector3 GetRotationEulerAnglesRadInWorldSpace() const { return GetRotationInWorldSpace().GetEulerAnglesRad(); }
		void SetRotationEulerAnglesRadInWorldSpace(const Vector3& eulerAngles) { SetRotationInWorldSpace(Quaternion::FromEulerAnglesRad(eulerAngles)); }
		void SetRotationEulerAnglesRadInWorldSpace(float xAngle, float yAngle, float zAngle) { SetRotationInWorldSpace(Quaternion::FromEulerAnglesRad(xAngle, yAngle, zAngle)); }

		Vector3 GetRotationEulerAnglesDegInLocalSpace() const { return m_rotation.GetEulerAnglesDeg(); }
		void SetRotationEulerAnglesDegInLocalSpace(const Vector3& eulerAngles) { SetRotationInLocalSpace(Quaternion::FromEulerAnglesDeg(eulerAngles)); }
		void SetRotationEulerAnglesDegInLocalSpace(float xAngle, float yAngle, float zAngle) { SetRotationInLocalSpace(Quaternion::FromEulerAnglesDeg(xAngle, yAngle, zAngle)); }

		Vector3 GetRotationEulerAnglesDegInWorldSpace() const { return GetRotationInWorldSpace().GetEulerAnglesDeg(); }
		void SetRotationEulerAnglesDegInWorldSpace(const Vector3& eulerAngles) { SetRotationInWorldSpace(Quaternion::FromEulerAnglesDeg(eulerAngles)); }
		void SetRotationEulerAnglesDegInWorldSpace(float xAngle, float yAngle, float zAngle) { SetRotationInWorldSpace(Quaternion::FromEulerAnglesDeg(xAngle, yAngle, zAngle)); }

		const Vector3& GetScaleInLocalSpace() const { return m_scale; }
		void SetScaleInLocalSpace(const Vector3& scale);
		void SetScaleInLocalSpace(float x, float y, float z) { SetScaleInLocalSpace(Vector3(x, y, z)); }

		Vector3 GetScaleInWorldSpace() const;
		void SetScaleInWorldSpace(const Vector3& scale);
		void SetScaleInWorldSpace(float x, float y, float z) { SetScaleInWorldSpace(Vector3(x, y, z)); }

		void TranslateInLocalSpace(const Vector3& translation);
		void TranslateInLocalSpace(float x, float y, float z) { TranslateInLocalSpace(Vector3(x, y, z)); }

		void TranslateInWorldSpace(const Vector3& translation);
		void TranslateInWorldSpace(float x, float y, float z) { TranslateInWorldSpace(Vector3(x, y, z)); }

		void TranslateRelativeTo(const Vector3& translation, const Transform& relativeTo);
		void TranslateRelativeTo(float x, float y, float z, const Transform& relativeTo) { TranslateRelativeTo(Vector3(x, y, z), relativeTo); }

		void RotateInLocalSpace(const Quaternion& rotation);

		void RotateRadInLocalSpace(const Vector3& eulerAngles) { RotateInLocalSpace(Quaternion::FromEulerAnglesRad(eulerAngles)); }
		void RotateRadInLocalSpace(float xAngle, float yAngle, float zAngle) { RotateInLocalSpace(Quaternion::FromEulerAnglesRad(xAngle, yAngle, zAngle)); }
		void RotateRadInLocalSpaceAroundAxisX(float xAngle) { RotateInLocalSpace(Quaternion::FromEulerAnglesRad(xAngle, 0.0f, 0.0f)); }
		void RotateRadInLocalSpaceAroundAxisY(float yAngle) { RotateInLocalSpace(Quaternion::FromEulerAnglesRad(0.0f, yAngle, 0.0f)); }
		void RotateRadInLocalSpaceAroundAxisZ(float zAngle) { RotateInLocalSpace(Quaternion::FromEulerAnglesRad(0.0f, 0.0f, zAngle)); }

		void RotateDegInLocalSpace(const Vector3& eulerAngles) { RotateInLocalSpace(Quaternion::FromEulerAnglesDeg(eulerAngles)); }
		void RotateDegInLocalSpace(float xAngle, float yAngle, float zAngle) { RotateInLocalSpace(Quaternion::FromEulerAnglesDeg(xAngle, yAngle, zAngle)); }
		void RotateDegInLocalSpaceAroundAxisX(float xAngle) { RotateInLocalSpace(Quaternion::FromEulerAnglesDeg(xAngle, 0.0f, 0.0f)); }
		void RotateDegInLocalSpaceAroundAxisY(float yAngle) { RotateInLocalSpace(Quaternion::FromEulerAnglesDeg(0.0f, yAngle, 0.0f)); }
		void RotateDegInLocalSpaceAroundAxisZ(float zAngle) { RotateInLocalSpace(Quaternion::FromEulerAnglesDeg(0.0f, 0.0f, zAngle)); }

		void RotateInWorldSpace(const Quaternion& rotation);

		void RotateRadInWorldSpace(const Vector3& eulerAngles) { RotateInWorldSpace(Quaternion::FromEulerAnglesRad(eulerAngles)); }
		void RotateRadInWorldSpace(float xAngle, float yAngle, float zAngle) { RotateInWorldSpace(Quaternion::FromEulerAnglesRad(xAngle, yAngle, zAngle)); }
		void RotateRadInWorldSpaceAroundAxisX(float xAngle) { RotateInWorldSpace(Quaternion::FromEulerAnglesRad(xAngle, 0.0f, 0.0f)); }
		void RotateRadInWorldSpaceAroundAxisY(float yAngle) { RotateInWorldSpace(Quaternion::FromEulerAnglesRad(0.0f, yAngle, 0.0f)); }
		void RotateRadInWorldSpaceAroundAxisZ(float zAngle) { RotateInWorldSpace(Quaternion::FromEulerAnglesRad(0.0f, 0.0f, zAngle)); }

		void RotateDegInWorldSpace(const Vector3& eulerAngles) { RotateInWorldSpace(Quaternion::FromEulerAnglesDeg(eulerAngles)); }
		void RotateDegInWorldSpace(float xAngle, float yAngle, float zAngle) { RotateInWorldSpace(Quaternion::FromEulerAnglesDeg(xAngle, yAngle, zAngle)); }
		void RotateDegInWorldSpaceAroundAxisX(float xAngle) { RotateInWorldSpace(Quaternion::FromEulerAnglesDeg(xAngle, 0.0f, 0.0f)); }
		void RotateDegInWorldSpaceAroundAxisY(float yAngle) { RotateInWorldSpace(Quaternion::FromEulerAnglesDeg(0.0f, yAngle, 0.0f)); }
		void RotateDegInWorldSpaceAroundAxisZ(float zAngle) { RotateInWorldSpace(Quaternion::FromEulerAnglesDeg(0.0f, 0.0f, zAngle)); }

		Matrix3x4 GetLocalTransformMatrix() const;
		Matrix3x4 GetWorldTransformMatrix() const;

		Vector3 GetForward() const;
		Vector3 GetBackward() const;
		Vector3 GetUp() const;
		Vector3 GetDown() const;
		Vector3 GetRight() const;
		Vector3 GetLeft() const;

		void SetSubHierarchyDirty();
		void SetSubHierarchyDirtyWorldTransformMarix();

	private:
		Vector3 m_position;		// Relative To Parent (local space)
		Quaternion m_rotation;	// Relative To Parent (local space)
		Vector3 m_scale;		// Relative To Parent (local space)

		static const unsigned char BITFLAG_DIRTY_NOTHING = 0b0000'0000;
		static const unsigned char BITFLAG_DIRTY_WORLD_TRANSFORM_MATRIX = 0b0000'0001;
		static const unsigned char BITFLAG_DIRTY_WORLD_ROTATION = 0b0000'0010;
		static const unsigned char BITFLAG_DIRTY_RIGHT = 0b0000'0100;
		static const unsigned char BITFLAG_DIRTY_UP = 0b0000'1000;
		static const unsigned char BITFLAG_DIRTY_FORWARD = 0b0001'0000;
		static const unsigned char BITFLAG_DIRTY_ALL = 0b1111'1111;

		// bit mask to cache values neading heavy calculation
		mutable unsigned char m_bfDirty;

		mutable Matrix3x4 m_worldTransformMatrixCache;
		mutable Quaternion m_worldRotationCache;
		mutable Vector3 m_rightCache;
		mutable Vector3 m_upCache;
		mutable Vector3 m_forwardCache;

		Entity* m_pEntity;

		Transform* m_pParent;
		std::vector<Transform*> m_lpChildren;
	};
}

////////////////////////////////////////////////////////////////////////////////
// Filename: Maths/Quaternion.cpp
////////////////////////////////////////////////////////////////////////////////

#include <quaternion.hpp>

#include <math.h>

#include <vector3.hpp>
#include <matrix3x4.hpp>


namespace Carbon
{
	const Quaternion Quaternion::IDENTITY = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);


	Quaternion::Quaternion(float X, float Y, float Z, float W) : X(X), Y(Y), Z(Z), W(W)
	{
	}


	Quaternion::Quaternion(const Quaternion& other)
	{
		X = other.X;
		Y = other.Y;
		Z = other.Z;
		W = other.W;
	}


	Quaternion::~Quaternion()
	{
	}


	Vector3 Quaternion::GetEulerAnglesRad() const
	{
		float attitude = asin(2.0f * (X * Y + Z * W));

		float XYplusZW = X * Y + Z * W;

		if (fabs(fabs(XYplusZW) - 0.5f) < MATH_EPSILON)
		{
			float heading = 2.0f * atan2(X, W);
			float bank = 0.0f;

			if (XYplusZW < 0.0f)
			{
				heading *= -1.0f;
			}

			return Vector3(bank, heading, attitude);
		}

		float heading = atan2(2.0f * (Y * W - X * Z), 1.0f - 2.0f * (Y * Y + Z * Z));
		float bank = atan2(2.0f * (X * W - Y * Z), 1.0f - 2.0f * (X * X + Z * Z));

		return Vector3(bank, heading, attitude);
	}


	Vector3 Quaternion::GetEulerAnglesDeg() const
	{
		return GetEulerAnglesRad() * RAD_TO_DEG;
	}


	void Quaternion::SetEulerAnglesRad(float x, float y, float z)
	{
		// Abbreviations for the various angular functions
		float c1 = cos(y * 0.5f);
		float s1 = sin(y * 0.5f);
		float c2 = cos(z * 0.5f);
		float s2 = sin(z * 0.5f);
		float c3 = cos(x * 0.5f);
		float s3 = sin(x * 0.5f);

		X = s1 * s2 * c3 + c1 * c2 * s3;
		Y = s1 * c2 * c3 + c1 * s2 * s3;
		Z = c1 * s2 * c3 - s1 * c2 * s3;
		W = c1 * c2 * c3 - s1 * s2 * s3;
	}


	void Quaternion::SetEulerAnglesRad(const Vector3& eulerAngles)
	{
		SetEulerAnglesRad(eulerAngles.X, eulerAngles.Y, eulerAngles.Z);
	}


	void Quaternion::SetEulerAnglesDeg(float x, float y, float z)
	{
		SetEulerAnglesRad(x * DEG_TO_RAD, y * DEG_TO_RAD, z * DEG_TO_RAD);
	}


	void Quaternion::SetEulerAnglesDeg(const Vector3& eulerAngles)
	{
		SetEulerAnglesRad(eulerAngles.X * DEG_TO_RAD, eulerAngles.Y * DEG_TO_RAD, eulerAngles.Z * DEG_TO_RAD);
	}


	Matrix3x4 Quaternion::ToMatrix() const
	{
		return Matrix3x4(
			1.0f - 2.0f * (Y * Y + Z * Z),
			2.0f * (X * Y - Z * W),
			2.0f * (X * Z + Y * W),
			0.0f,

			2.0f * (X * Y + Z * W),
			1.0f - 2.0f * (X * X + Z * Z),
			2.0f * Y * Z - 2.0f * X * W,
			0.0f,

			2.0f * (X * Z - Y * W),
			2.0f * (Y * Z + X * W),
			1.0f - 2.0f * (X * X + Y * Y),
			0.0f);
	}


	bool Quaternion::operator == (const Quaternion& other) const
	{
		return fabs(X - other.X) < MATH_EPSILON && fabs(Y - other.Y) < MATH_EPSILON && fabs(Z - other.Z) < MATH_EPSILON && fabs(W - other.W) < MATH_EPSILON;
	}


	bool Quaternion::operator != (const Quaternion& other) const
	{
		return !(*this == other);
	}


	float& Quaternion::operator [] (int index)
	{
		switch (index)
		{
		case 0: return X;
		case 1: return Y;
		case 2: return Z;
		case 3: return W;

		default: throw std::invalid_argument("index out of bound");
		}
	}


	std::ostream& operator << (std::ostream& os, const Quaternion& quaternion)
	{
		os << '(' << quaternion.X << ", " << quaternion.Y << ", " << quaternion.Z << ", " << quaternion.W << ')';
		return os;
	}


	Quaternion Quaternion::operator * (const Quaternion& other) const	// q1 * q2
	{
		return Quaternion(
			W * other.X + X * other.W + Y * other.Z - Z * other.Y,
			W * other.Y + Y * other.W + Z * other.X - X * other.Z,
			W * other.Z + Z * other.W + X * other.Y - Y * other.X,
			W * other.W - X * other.X - Y * other.Y - Z * other.Z
		);
	}


	Vector3 Quaternion::operator * (const Vector3& vector) const
	{
		Quaternion inverse(-X, -Y, -Z, W); // assuming quaternion is normalized,  q* = q(-1)

		Quaternion result = (*this) * Quaternion(vector.X, vector.Y, vector.Z, 0.0f) * inverse;

		return Vector3(result.X, result.Y, result.Z);
	}


	Quaternion Quaternion::operator * (float k) const
	{
		return Quaternion(X * k, Y * k, Z * k, W * k);
	}


	Quaternion& Quaternion::operator *= (float k)
	{
		X *= k;
		Y *= k;
		Z *= k;
		W *= k;
		return *this;
	}

	void Quaternion::Normalize(Quaternion& quaternion)
	{
		float d = quaternion.W * quaternion.W + quaternion.X * quaternion.X + quaternion.Y * quaternion.Y + quaternion.Z * quaternion.Z;

		if (0.0f == d) {

			quaternion = Quaternion::IDENTITY;

			return;
		}

		d = 1.0f / sqrt(d);

		quaternion.X *= d;
		quaternion.Y *= d;
		quaternion.Z *= d;
		quaternion.W *= d;
	}


	// Assume from and to are unit vectors
	Quaternion Quaternion::RotationBetween(const Vector3& from, const Vector3& to)
	{
		if (Vector3::Distance(from, to) <= MATH_EPSILON)	return Quaternion::IDENTITY;

		if (Vector3::Distance(from, -to) <= MATH_EPSILON) return Quaternion(0.0f, 1.0f, 0.0f, 0.0f); // 180° rotation on Y (axis doesn't matter, but UP seems more natural)

		Vector3 v = Vector3::Cross(from, to);

		float fromMag = from.Magnitude();
		float toMag = to.Magnitude();

		Quaternion q(v.X, v.Y, v.Z, sqrt(fromMag * fromMag * toMag * toMag) + Vector3::Dot(from, to));

		Quaternion::Normalize(q);

		return q;
	}


	Quaternion Quaternion::FromEulerAnglesRad(const Vector3& eulerAngles)
	{
		Quaternion q;

		q.SetEulerAnglesRad(eulerAngles.X, eulerAngles.Y, eulerAngles.Z);

		return q;
	}


	Quaternion Quaternion::FromEulerAnglesRad(float x, float y, float z)
	{
		Quaternion q;

		q.SetEulerAnglesRad(x, y, z);

		return q;
	}


	Quaternion Quaternion::FromEulerAnglesDeg(const Vector3& eulerAngles)
	{
		Quaternion q;

		q.SetEulerAnglesRad(eulerAngles.X * DEG_TO_RAD, eulerAngles.Y * DEG_TO_RAD, eulerAngles.Z * DEG_TO_RAD);

		return q;
	}


	Quaternion Quaternion::FromEulerAnglesDeg(float x, float y, float z)
	{
		Quaternion q;

		q.SetEulerAnglesRad(x * DEG_TO_RAD, y * DEG_TO_RAD, z * DEG_TO_RAD);

		return q;
	}
}

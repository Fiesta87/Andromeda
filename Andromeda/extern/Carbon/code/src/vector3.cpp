#include <vector3.hpp>

#include <math.h>

namespace Carbon
{
	const Vector3 Vector3::ZERO = Vector3(0.0f, 0.0f, 0.0f);
	const Vector3 Vector3::ONE = Vector3(1.0f, 1.0f, 1.0f);

	const Vector3 Vector3::FORWARD = Vector3(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::BACKWARD = Vector3(-1.0f, 0.0f, 0.0f);

	const Vector3 Vector3::UP = Vector3(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::DOWN = Vector3(0.0f, -1.0f, 0.0f);

	const Vector3 Vector3::RIGHT = Vector3(0.0f, 0.0f, 1.0f);
	const Vector3 Vector3::LEFT = Vector3(0.0f, 0.0f, -1.0f);


	Vector3::Vector3(float X, float Y, float Z) : X(X), Y(Y), Z(Z)
	{
	}


	Vector3::Vector3(const Vector3& other)
	{
		X = other.X;
		Y = other.Y;
		Z = other.Z;
	}


	Vector3::~Vector3()
	{
	}


	float Vector3::Magnitude() const
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}


	Vector3 Vector3::Normalized() const
	{
		float magnitude = sqrt(X * X + Y * Y + Z * Z);

		return Vector3(X / magnitude, Y / magnitude, Z / magnitude);
	}


	float Vector3::SqrMagnitude() const
	{
		return X * X + Y * Y + Z * Z;
	}


	bool Vector3::operator == (const Vector3& other) const
	{
		return fabs(X - other.X) < MATH_EPSILON && fabs(Y - other.Y) < MATH_EPSILON && fabs(Z - other.Z) < MATH_EPSILON;
	}


	bool Vector3::operator != (const Vector3& other) const
	{
		return !(*this == other);
	}


	float& Vector3::operator [] (int index)
	{
		switch (index)
		{
		case 0: return X;
		case 1: return Y;
		case 2: return Z;

		default: throw std::invalid_argument("index out of bound");
		}
	}


	std::ostream& operator << (std::ostream& os, const Vector3& vector)
	{
		os << '(' << vector.X << ", " << vector.Y << ", " << vector.Z << ')';
		return os;
	}


	Vector3 Vector3::operator + (const Vector3& other) const
	{
		return Vector3(X + other.X, Y + other.Y, Z + other.Z);
	}


	Vector3& Vector3::operator += (const Vector3& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;
		return *this;
	}


	Vector3 Vector3::operator - (const Vector3& other) const
	{
		return Vector3(X - other.X, Y - other.Y, Z - other.Z);
	}


	Vector3& Vector3::operator -= (const Vector3& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;
		return *this;
	}


	Vector3 Vector3::operator - () const
	{
		return Vector3(-X, -Y, -Z);
	}


	Vector3 Vector3::operator * (float k) const
	{
		return Vector3(X * k, Y * k, Z * k);
	}


	Vector3& Vector3::operator *= (float k)
	{
		X *= k;
		Y *= k;
		Z *= k;
		return *this;
	}


	Vector3 operator * (float k, const Vector3& vector)
	{
		return Vector3(vector.X * k, vector.Y * k, vector.Z * k);
	}


	Vector3 Vector3::operator / (float k) const
	{
		return Vector3(X / k, Y / k, Z / k);
	}


	Vector3& Vector3::operator /= (float k)
	{
		X /= k;
		Y /= k;
		Z /= k;
		return *this;
	}


	Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3(
			a.Y * b.Z - a.Z * b.Y,
			a.Z * b.X - a.X * b.Z,
			a.X * b.Y - a.Y * b.X);
	}


	float Vector3::Dot(const Vector3& a, const Vector3& b)
	{
		return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
	}


	Vector3 Vector3::HadamardProduct(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
	}


	Vector3 Vector3::HadamardDivision(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.X / b.X, a.Y / b.Y, a.Z / b.Z);
	}


	void Vector3::Normalize(Vector3& vector)
	{
		float magnitude = sqrt(vector.X * vector.X + vector.Y * vector.Y + vector.Z * vector.Z);

		vector.X /= magnitude;
		vector.Y /= magnitude;
		vector.Z /= magnitude;
	}


	float Vector3::Distance(const Vector3& a, const Vector3& b)
	{
		float x = a.X - b.X;
		float y = a.Y - b.Y;
		float z = a.Z - b.Z;

		return sqrtf(x * x + y * y + z * z);
	}


	float Vector3::AngleDeg(const Vector3& a, const Vector3& b)
	{
		return std::acosf(Vector3::Dot(a, b) / (a.Magnitude() * b.Magnitude())) * RAD_TO_DEG;
	}


	float Vector3::AngleRad(const Vector3& a, const Vector3& b)
	{
		return std::acosf(Vector3::Dot(a, b) / (a.Magnitude() * b.Magnitude()));
	}
}

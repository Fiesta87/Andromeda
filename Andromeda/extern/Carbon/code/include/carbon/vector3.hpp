#pragma once

#include <carbon/carbon.hpp>

#include <iostream>

namespace Carbon
{
	////////////////////////////////////////////////////////////////////////////////
	// Vector3
	////////////////////////////////////////////////////////////////////////////////
	class Vector3
	{

	public:
		static const Vector3 ZERO;		// (0, 0, 0)
		static const Vector3 ONE;		// (1, 1, 1)
		static const Vector3 FORWARD;	// X positive ( 1,  0,  0)
		static const Vector3 BACKWARD;	// X negative (-1,  0,  0)
		static const Vector3 UP;		// Y positive ( 0,  1,  0)
		static const Vector3 DOWN;		// Y negative ( 0, -1,  0)
		static const Vector3 RIGHT;		// Z positive ( 0,  0,  1)
		static const Vector3 LEFT;		// Z negative ( 0,  0, -1)

	public:
		Vector3(float X = 0.0f, float Y = 0.0f, float Z = 0.0f);
		Vector3(const Vector3& other);
		~Vector3();

	public:
		float Magnitude() const;

		Vector3 Normalized() const;

		float SqrMagnitude() const;

	public:
		bool operator == (const Vector3& other) const;

		bool operator != (const Vector3& other) const;

		float& operator [] (int index);

		friend std::ostream& operator << (std::ostream& os, const Vector3& vector);

		Vector3 operator + (const Vector3& other) const;

		Vector3& operator += (const Vector3& other);

		Vector3 operator - (const Vector3& other) const;

		Vector3& operator -= (const Vector3& other);

		Vector3 operator - () const;

		Vector3 operator * (float k) const;

		Vector3& operator *= (float k);

		friend Vector3 operator * (float k, const Vector3& vector);

		Vector3 operator / (float k) const;

		Vector3& operator /= (float k);

	public:
		static Vector3 Cross(const Vector3& a, const Vector3& b);

		static float Dot(const Vector3& a, const Vector3& b);

		static Vector3 HadamardProduct(const Vector3& a, const Vector3& b);

		static Vector3 HadamardDivision(const Vector3& a, const Vector3& b);

		static void Normalize(Vector3& vector);

		static float Distance(const Vector3& a, const Vector3& b);

		static float AngleDeg(const Vector3& a, const Vector3& b);

		static float AngleRad(const Vector3& a, const Vector3& b);

	public:
		float X;
		float Y;
		float Z;
	};
}

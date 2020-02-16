#pragma once

#include <carbon.hpp>

#include <iostream>

namespace Carbon
{
	class Vector3;


	////////////////////////////////////////////////////////////////////////////////
	// Matrix3x4
	// 
	// Optimized matrix representing a standard 4x4 matrix with 0, 0, 0, 1 on the 4th line.
	// Calculations with Vectors considers they are vectors, not points :
	//	homogeneous coordinate of vectors are assumed to be (X, Y, Z, 0).
	////////////////////////////////////////////////////////////////////////////////
	class Matrix3x4
	{

	public:

		// | 0, 0, 0, 0 |
		// | 0, 0, 0, 0 |
		// | 0, 0, 0, 0 |
		// | 0, 0, 0, 1 |	implicit line
		static const Matrix3x4 ZERO;

		// | 1, 0, 0, 0 |
		// | 0, 1, 0, 0 |
		// | 0, 0, 1, 0 |
		// | 0, 0, 0, 1 |	implicit line
		static const Matrix3x4 IDENTITY;

	public:
		Matrix3x4();
		Matrix3x4(
			float a, float b, float c, float d,
			float e, float f, float g, float h,
			float i, float j, float k, float l);
		Matrix3x4(const Matrix3x4& other);
		~Matrix3x4();

	public:
		float Determinant() const;

		Matrix3x4 Inverse() const;

	public:
		bool operator == (const Matrix3x4& other) const;

		bool operator != (const Matrix3x4& other) const;

		float& operator [] (int index);

		friend std::ostream& operator << (std::ostream& os, const Matrix3x4& matrix);

		Matrix3x4 operator + (const Matrix3x4& other) const;

		Matrix3x4 operator += (const Matrix3x4& other);

		Matrix3x4 operator - (const Matrix3x4& other) const;

		Matrix3x4 operator -= (const Matrix3x4& other);

		Matrix3x4 operator * (const Matrix3x4& other) const;

		Vector3 operator * (const Vector3& vector) const;

		//friend Vector3 operator * (const Vector3& vector, const Matrix3x4& matrice);

	public:
		float m00;
		float m01;
		float m02;
		float m03;

		float m10;
		float m11;
		float m12;
		float m13;

		float m20;
		float m21;
		float m22;
		float m23;
	};
}

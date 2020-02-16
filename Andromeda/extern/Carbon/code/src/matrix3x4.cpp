#include <matrix3x4.hpp>

#include <vector3.hpp>

namespace Carbon
{
	const Matrix3x4 Matrix3x4::IDENTITY = Matrix3x4();
	const Matrix3x4 Matrix3x4::ZERO = Matrix3x4(
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	/*	0.0f, 0.0f, 0.0f, 1.0f	implicit*/);


	Matrix3x4::Matrix3x4() :
		m00(1.0f),
		m01(0.0f),
		m02(0.0f),
		m03(0.0f),

		m10(0.0f),
		m11(1.0f),
		m12(0.0f),
		m13(0.0f),

		m20(0.0f),
		m21(0.0f),
		m22(1.0f),
		m23(0.0f)
	{
	}


	Matrix3x4::Matrix3x4(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23) :
		m00(m00),
		m01(m01),
		m02(m02),
		m03(m03),

		m10(m10),
		m11(m11),
		m12(m12),
		m13(m13),

		m20(m20),
		m21(m21),
		m22(m22),
		m23(m23)
	{
	}


	Matrix3x4::Matrix3x4(const Matrix3x4& other) :
		m00(other.m00),
		m01(other.m01),
		m02(other.m02),
		m03(other.m03),

		m10(other.m10),
		m11(other.m11),
		m12(other.m12),
		m13(other.m13),

		m20(other.m20),
		m21(other.m21),
		m22(other.m22),
		m23(other.m23)
	{
	}


	Matrix3x4::~Matrix3x4()
	{
	}


	float Matrix3x4::Determinant() const
	{
		return -
			m02 * m11 * m20 + m01 * m12 * m20 +
			m02 * m10 * m21 - m00 * m12 * m21 -
			m01 * m10 * m22 + m00 * m11 * m22;
	}


	Matrix3x4 Matrix3x4::Inverse() const
	{
		float inverseDeterminant = 1.0f / Determinant();

		return Matrix3x4(
			inverseDeterminant * (m11 * m22 - m12 * m21),
			inverseDeterminant * (m02 * m21 - m01 * m22),
			inverseDeterminant * (m01 * m12 - m02 * m11),
			inverseDeterminant * (m03 * m12 * m21 - m02 * m13 * m21 - m03 * m11 * m22 + m01 * m13 * m22 + m02 * m11 * m23 - m01 * m12 * m23),

			inverseDeterminant * (m12 * m20 - m10 * m22),
			inverseDeterminant * (m00 * m22 - m02 * m20),
			inverseDeterminant * (m02 * m10 - m00 * m12),
			inverseDeterminant * (m02 * m13 * m20 - m03 * m12 * m20 + m03 * m10 * m22 - m00 * m13 * m22 - m02 * m10 * m23 + m00 * m12 * m23),

			inverseDeterminant * (m10 * m21 - m11 * m20),
			inverseDeterminant * (m01 * m20 - m00 * m21),
			inverseDeterminant * (m00 * m11 - m01 * m10),
			inverseDeterminant * (m03 * m11 * m20 - m01 * m13 * m20 - m03 * m10 * m21 + m00 * m13 * m21 + m01 * m10 * m23 - m00 * m11 * m23));
	}


	bool Matrix3x4::operator == (const Matrix3x4& other) const
	{
		return
			fabs(m00 - other.m00) < MATH_EPSILON && fabs(m01 - other.m01) < MATH_EPSILON && fabs(m02 - other.m02) < MATH_EPSILON && fabs(m03 - other.m03) < MATH_EPSILON &&
			fabs(m10 - other.m10) < MATH_EPSILON && fabs(m11 - other.m11) < MATH_EPSILON && fabs(m12 - other.m12) < MATH_EPSILON && fabs(m13 - other.m13) < MATH_EPSILON &&
			fabs(m20 - other.m20) < MATH_EPSILON && fabs(m21 - other.m21) < MATH_EPSILON && fabs(m22 - other.m22) < MATH_EPSILON && fabs(m23 - other.m23) < MATH_EPSILON;
	}


	bool Matrix3x4::operator != (const Matrix3x4& other) const
	{
		return !(*this == other);
	}


	float& Matrix3x4::operator [] (int index)
	{
		switch (index)
		{
		case 0: return m00;
		case 1: return m01;
		case 2: return m02;
		case 3: return m03;

		case 4: return m10;
		case 5: return m11;
		case 6: return m12;
		case 7: return m13;

		case 8: return m20;
		case 9: return m21;
		case 10: return m22;
		case 11: return m23;

		default: throw std::invalid_argument("index out of bound");
		}
	}


	std::ostream& operator << (std::ostream& os, const Matrix3x4& matrix)
	{
		os << std::endl
			<< "| " << matrix.m00 << " " << matrix.m01 << " " << matrix.m02 << " " << matrix.m03 << " |" << std::endl
			<< "| " << matrix.m10 << " " << matrix.m11 << " " << matrix.m12 << " " << matrix.m13 << " |" << std::endl
			<< "| " << matrix.m20 << " " << matrix.m21 << " " << matrix.m22 << " " << matrix.m23 << " |" << std::endl;

		return os;
	}


	Matrix3x4 Matrix3x4::operator + (const Matrix3x4& other) const
	{
		return Matrix3x4(
			m00 + other.m00, m01 + other.m01, m02 + other.m02, m03 + other.m03,
			m10 + other.m10, m11 + other.m11, m12 + other.m12, m13 + other.m13,
			m20 + other.m20, m21 + other.m21, m22 + other.m22, m23 + other.m23);
	}


	Matrix3x4 Matrix3x4::operator += (const Matrix3x4& other)
	{
		m00 += other.m00;
		m01 += other.m01;
		m02 += other.m02;
		m03 += other.m03;

		m10 += other.m10;
		m11 += other.m11;
		m12 += other.m12;
		m13 += other.m13;

		m20 += other.m20;
		m21 += other.m21;
		m22 += other.m22;
		m23 += other.m23;

		return *this;
	}


	Matrix3x4 Matrix3x4::operator - (const Matrix3x4& other) const
	{
		return Matrix3x4(
			m00 - other.m00, m01 - other.m01, m02 - other.m02, m03 - other.m03,
			m10 - other.m10, m11 - other.m11, m12 - other.m12, m13 - other.m13,
			m20 - other.m20, m21 - other.m21, m22 - other.m22, m23 - other.m23);
	}


	Matrix3x4 Matrix3x4::operator -= (const Matrix3x4& other)
	{
		m00 -= other.m00;
		m01 -= other.m01;
		m02 -= other.m02;
		m03 -= other.m03;

		m10 -= other.m10;
		m11 -= other.m11;
		m12 -= other.m12;
		m13 -= other.m13;

		m20 -= other.m20;
		m21 -= other.m21;
		m22 -= other.m22;
		m23 -= other.m23;

		return *this;
	}


	Matrix3x4 Matrix3x4::operator * (const Matrix3x4& other) const
	{
		return Matrix3x4(
			m00 * other.m00 + m01 * other.m10 + m02 * other.m20,
			m00 * other.m01 + m01 * other.m11 + m02 * other.m21,
			m00 * other.m02 + m01 * other.m12 + m02 * other.m22,
			m00 * other.m03 + m01 * other.m13 + m02 * other.m23 + m03,

			m10 * other.m00 + m11 * other.m10 + m12 * other.m20,
			m10 * other.m01 + m11 * other.m11 + m12 * other.m21,
			m10 * other.m02 + m11 * other.m12 + m12 * other.m22,
			m10 * other.m03 + m11 * other.m13 + m12 * other.m23 + m13,

			m20 * other.m00 + m21 * other.m10 + m22 * other.m20,
			m20 * other.m01 + m21 * other.m11 + m22 * other.m21,
			m20 * other.m02 + m21 * other.m12 + m22 * other.m22,
			m20 * other.m03 + m21 * other.m13 + m22 * other.m23 + m23);
	}


	Vector3 Matrix3x4::operator * (const Vector3& vector) const
	{
		return Vector3(
			m00 * vector.X + m01 * vector.Y + m02 * vector.Z,
			m10 * vector.X + m11 * vector.Y + m12 * vector.Z,
			m20 * vector.X + m21 * vector.Y + m22 * vector.Z);
	}

	/*
	Vector3 operator * (const Vector3& vector, const Matrix3x4& matrice)
	{
		return Vector3( vector.X * matrice.m00 + vector.Y * matrice.m10 + vector.Z * matrice.m20,
						vector.X * matrice.m01 + vector.Y * matrice.m11 + vector.Z * matrice.m21,
						vector.X * matrice.m02 + vector.Y * matrice.m12 + vector.Z * matrice.m22);
	}*/
}

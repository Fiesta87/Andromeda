#pragma once

#include <pulsar/test.hpp>
#include <carbon/matrix3x4.hpp>

namespace Carbon
{
	TEST_BEGIN_TESTMODULE(Matrix3x4)

	TEST_ADD_UNITTEST(ConstructorNoParameters)
	{
		Matrix3x4 m;

		TestAssertEquals(m.m00, 1.0f);
		TestAssertEquals(m.m01, 0.0f);
		TestAssertEquals(m.m02, 0.0f);
		TestAssertEquals(m.m03, 0.0f);

		TestAssertEquals(m.m10, 0.0f);
		TestAssertEquals(m.m11, 1.0f);
		TestAssertEquals(m.m12, 0.0f);
		TestAssertEquals(m.m13, 0.0f);

		TestAssertEquals(m.m20, 0.0f);
		TestAssertEquals(m.m21, 0.0f);
		TestAssertEquals(m.m22, 1.0f);
		TestAssertEquals(m.m23, 0.0f);
	};


	TEST_ADD_UNITTEST(ConstructorWithParameters)
	{
		Matrix3x4 m(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		TestAssertEquals(m.m00, 1.0f);
		TestAssertEquals(m.m01, 2.0f);
		TestAssertEquals(m.m02, 3.0f);
		TestAssertEquals(m.m03, 4.0f);

		TestAssertEquals(m.m10, 5.0f);
		TestAssertEquals(m.m11, 6.0f);
		TestAssertEquals(m.m12, 7.0f);
		TestAssertEquals(m.m13, 8.0f);

		TestAssertEquals(m.m20, 9.0f);
		TestAssertEquals(m.m21, 10.0f);
		TestAssertEquals(m.m22, 11.0f);
		TestAssertEquals(m.m23, 12.0f);
	};


	TEST_ADD_UNITTEST(OperatorEqualTrue)
	{
		Matrix3x4 m1(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		Matrix3x4 m2(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		TestAssertEquals(m1 == m1, true);
		TestAssertEquals(m1 == m2, true);
	};


	TEST_ADD_UNITTEST(OperatorEqualFalse)
	{
		Matrix3x4 m1(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		Matrix3x4 m2(116.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		TestAssertEquals(m1 == m2, false);
	};


	TEST_ADD_UNITTEST(OperatorNotEqualTrue)
	{
		Matrix3x4 m1(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		Matrix3x4 m2(116.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		TestAssertEquals(m1 != m2, true);
	};


	TEST_ADD_UNITTEST(OperatorNotEqualFalse)
	{
		Matrix3x4 m1(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		Matrix3x4 m2(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		TestAssertEquals(m1 != m1, false);
		TestAssertEquals(m1 != m2, false);
	};


	TEST_ADD_UNITTEST(StaticConst)
	{
		TestAssertEquals(Matrix3x4::ZERO, Matrix3x4(0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f));

		TestAssertEquals(Matrix3x4::IDENTITY, Matrix3x4(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f));
	};


	TEST_ADD_UNITTEST(ConstructorCopy)
	{
		Matrix3x4 m(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		TestAssertEquals(Matrix3x4(m), m);
	};


	TEST_ADD_UNITTEST(Determinant)
	{
		Matrix3x4 m(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		TestAssertEquals(m.Determinant(), 0.0f);

		Matrix3x4 m2(0.3306703f, 0.2102600f, -0.9200261f, 0.0f,
			-0.3140753f, 0.9438146f, 0.1028135f, 0.0f,
			0.8899516f, 0.2549601f, 0.3781289f, 0.0f);

		TestAssertEquals(m2.Determinant(), 1.0f);
	};


	TEST_ADD_UNITTEST(Inverse)
	{
		Matrix3x4 m(0.3306703f, 0.2102600f, -0.9200261f, 0.0f,
			-0.3140753f, 0.9438146f, 0.1028135f, 0.0f,
			0.8899516f, 0.2549601f, 0.3781289f, 0.0f);

		TestAssertEquals(m.Inverse(), Matrix3x4(0.3306702f, -0.3140753f, 0.8899516f, 0.0f,
			0.2102599f, 0.9438146f, 0.2549601f, 0.0f,
			-0.9200259f, 0.1028134f, 0.3781289f, 0.0f));
	};


	TEST_ADD_UNITTEST(OperatorBracket)
	{
		Matrix3x4 m(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		TestAssertEquals(m[0], 1.0f);
		TestAssertEquals(m[1], 2.0f);
		TestAssertEquals(m[2], 3.0f);
		TestAssertEquals(m[3], 4.0f);

		TestAssertEquals(m[4], 5.0f);
		TestAssertEquals(m[5], 6.0f);
		TestAssertEquals(m[6], 7.0f);
		TestAssertEquals(m[7], 8.0f);

		TestAssertEquals(m[8], 9.0f);
		TestAssertEquals(m[9], 10.0f);
		TestAssertEquals(m[10], 11.0f);
		TestAssertEquals(m[11], 12.0f);
	};


	TEST_ADD_UNITTEST(OperatorAddition)
	{
		Matrix3x4 m1(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		Matrix3x4 m2(5.0f, 1.0f, 11.0f, 9.0f,
			10.0f, 4.0f, 3.0f, 2.0f,
			7.0f, 12.0f, 8.0f, 6.0f);

		TestAssertEquals(m1 + m2, Matrix3x4(6.0f, 3.0f, 14.0f, 13.0f,
			15.0f, 10.0f, 10.0f, 10.0f,
			16.0f, 22.0f, 19.0f, 18.0f));
	};


	TEST_ADD_UNITTEST(OperatorAdditionEqual)
	{
		Matrix3x4 m1(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f);

		Matrix3x4 m2(5.0f, 1.0f, 11.0f, 9.0f,
			10.0f, 4.0f, 3.0f, 2.0f,
			7.0f, 12.0f, 8.0f, 6.0f);

		m1 += m2;

		TestAssertEquals(m1, Matrix3x4(6.0f, 3.0f, 14.0f, 13.0f,
			15.0f, 10.0f, 10.0f, 10.0f,
			16.0f, 22.0f, 19.0f, 18.0f));
	};


	TEST_ADD_UNITTEST(OperatorSubtraction)
	{
		Matrix3x4 m1(6.0f, 3.0f, 14.0f, 13.0f,
			15.0f, 10.0f, 10.0f, 10.0f,
			16.0f, 22.0f, 19.0f, 18.0f);

		Matrix3x4 m2(5.0f, 1.0f, 11.0f, 9.0f,
			10.0f, 4.0f, 3.0f, 2.0f,
			7.0f, 12.0f, 8.0f, 6.0f);

		TestAssertEquals(m1 - m2, Matrix3x4(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f));
	};


	TEST_ADD_UNITTEST(OperatorSubtractionEqual)
	{
		Matrix3x4 m1(6.0f, 3.0f, 14.0f, 13.0f,
			15.0f, 10.0f, 10.0f, 10.0f,
			16.0f, 22.0f, 19.0f, 18.0f);

		Matrix3x4 m2(5.0f, 1.0f, 11.0f, 9.0f,
			10.0f, 4.0f, 3.0f, 2.0f,
			7.0f, 12.0f, 8.0f, 6.0f);

		m1 -= m2;

		TestAssertEquals(m1, Matrix3x4(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f));
	};


	TEST_ADD_UNITTEST(OperatorMultiplyMatrix)
	{
		Matrix3x4 m1(0.3306703f, 0.2102600f, -0.9200261f, 0.0f,
			-0.3140753f, 0.9438146f, 0.1028135f, 0.0f,
			0.8899516f, 0.2549601f, 0.3781289f, 0.0f);

		Matrix3x4 m2(0.3306702f, -0.3140753f, 0.8899516f, 0.0f,
			0.2102599f, 0.9438146f, 0.2549601f, 0.0f,
			-0.9200259f, 0.1028134f, 0.3781289f, 0.0f);

		TestAssertEquals(m1 * m2, Matrix3x4::IDENTITY);
	};


	TEST_ADD_UNITTEST(OperatorMultiplyVector)
	{
		Matrix3x4 m(0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			-1.0f, 0.0f, 0.0f, 0.0f);

		Vector3 v(0.7071067811865476f, 0.7071067811865476f, 0.0f);

		TestAssertEquals(m * v, Vector3(0.0f, 0.7071067811865476f, -0.7071067811865476f));
	};

	TEST_END_TESTMODULE(Vector3)
}

#pragma once

#include <pulsar/test.hpp>
#include <carbon/vector3.hpp>

namespace Carbon
{
	TEST_BEGIN_TESTMODULE(Vector3)

	TEST_ADD_UNITTEST(ConstructorNoParameters)
	{
		Vector3 v;
		
		TestAssertEquals(v.X, 0.0f);
		TestAssertEquals(v.Y, 0.0f);
		TestAssertEquals(v.Z, 0.0f);
	};


	TEST_ADD_UNITTEST(ConstructorWithParameters)
	{
		Vector3 v(1.0f, 2.0f, 3.0f);

		TestAssertEquals(v.X, 1.0f);
		TestAssertEquals(v.Y, 2.0f);
		TestAssertEquals(v.Z, 3.0f);
	};


	TEST_ADD_UNITTEST(OperatorEqualTrue)
	{
		Vector3 v1(1.0f, 2.0f, 3.0f);
		Vector3 v2(1.0f, 2.0f, 3.0f);

		TestAssertEquals(v1 == v1, true);
		TestAssertEquals(v1 == v2, true);
	};


	TEST_ADD_UNITTEST(OperatorEqualFalse)
	{
		Vector3 v1(1.0f, 2.0f, 3.0f);
		Vector3 v2(1.0f, 2.0f, 4.0f);

		TestAssertEquals(v1 == v2, false);
	};


	TEST_ADD_UNITTEST(OperatorNotEqualTrue)
	{
		Vector3 v1(1.0f, 0.0f, 3.0f);
		Vector3 v2(1.0f, 2.0f, 3.0f);

		TestAssertEquals(v1 != v2, true);
	};


	TEST_ADD_UNITTEST(OperatorNotEqualFalse)
	{
		Vector3 v1(1.0f, 2.0f, 3.0f);
		Vector3 v2(1.0f, 2.0f, 3.0f);

		TestAssertEquals(v1 != v1, false);
		TestAssertEquals(v1 != v2, false);
	};


	TEST_ADD_UNITTEST(StaticConst)
	{
		TestAssertEquals(Vector3::ZERO, Vector3(0.0f, 0.0f, 0.0f));
		TestAssertEquals(Vector3::ONE, Vector3(1.0f, 1.0f, 1.0f));
		TestAssertEquals(Vector3::FORWARD, Vector3(1.0f, 0.0f, 0.0f));
		TestAssertEquals(Vector3::BACKWARD, Vector3(-1.0f, 0.0f, 0.0f));
		TestAssertEquals(Vector3::UP, Vector3(0.0f, 1.0f, 0.0f));
		TestAssertEquals(Vector3::DOWN, Vector3(0.0f, -1.0f, 0.0f));
		TestAssertEquals(Vector3::RIGHT, Vector3(0.0f, 0.0f, 1.0f));
		TestAssertEquals(Vector3::LEFT, Vector3(0.0f, 0.0f, -1.0f));
	};


	TEST_ADD_UNITTEST(ConstructorCopy)
	{
		Vector3 v(-61.0f, 15.1f, 216.165f);

		TestAssertEquals(Vector3(v), v);
	};


	TEST_ADD_UNITTEST(Magnitude)
	{
		Vector3 v(5.0f, 9.0f, 14.0f);

		TestAssertEquals(v.Magnitude(), 17.3781471f);
	};


	TEST_ADD_UNITTEST(Normalized)
	{
		Vector3 v(5.0f, 9.0f, 14.0f);
		Vector3 normalizedV(0.28771767f, 0.51789180f, 0.80560948f);

		TestAssertEquals(v.Normalized(), normalizedV);
	};


	TEST_ADD_UNITTEST(SqrMagnitude)
	{
		Vector3 v(5.0f, 9.0f, 14.0f);

		TestAssertEquals(v.SqrMagnitude(), 302.0f);
	};


	TEST_ADD_UNITTEST(OperatorBracket)
	{
		Vector3 v(5.0f, 9.0f, 14.0f);

		TestAssertEquals(v[0], 5.0f);
		TestAssertEquals(v[1], 9.0f);
		TestAssertEquals(v[2], 14.0f);
	};


	TEST_ADD_UNITTEST(OperatorAddition)
	{
		Vector3 v1(5.0f, 9.0f, 14.0f);
		Vector3 v2(3.0f, -7.0f, 0.0f);
		Vector3 v3(8.0f, 2.0f, 14.0f);

		TestAssertEquals(v1 + v2, v3);
	};


	TEST_ADD_UNITTEST(OperatorAdditionEqual)
	{
		Vector3 v1(5.0f, 9.0f, 14.0f);
		Vector3 v2(3.0f, -7.0f, 0.0f);
		Vector3 v3(8.0f, 2.0f, 14.0f);

		v1 += v2;

		TestAssertEquals(v1, v3);
	};


	TEST_ADD_UNITTEST(OperatorSubtraction)
	{
		Vector3 v1(5.0f, 9.0f, 14.0f);
		Vector3 v2(3.0f, -7.0f, 30.0f);
		Vector3 v3(2.0f, 16.0f, -16.0f);

		TestAssertEquals(v1 - v2, v3);
	};


	TEST_ADD_UNITTEST(OperatorSubtractionEqual)
	{
		Vector3 v1(5.0f, 9.0f, 14.0f);
		Vector3 v2(3.0f, -7.0f, 30.0f);
		Vector3 v3(2.0f, 16.0f, -16.0f);

		v1 -= v2;

		TestAssertEquals(v1, v3);
	};


	TEST_ADD_UNITTEST(OperatorInverse)
	{
		Vector3 v1(5.0f, -9.0f, 14.0f);
		Vector3 v2(-5.0f, 9.0f, -14.0f);

		TestAssertEquals(-v1, v2);
	};


	TEST_ADD_UNITTEST(OperatorMultiplyConstant)
	{
		Vector3 v1(5.0f, -9.0f, 14.0f);
		Vector3 v2(15.0f, -27.0f, 42.0f);

		TestAssertEquals(v1 * 3.0f, v2);
	};


	TEST_ADD_UNITTEST(OperatorMultiplyEqualConstant)
	{
		Vector3 v1(5.0f, -9.0f, 14.0f);
		Vector3 v2(15.0f, -27.0f, 42.0f);

		v1 *= 3.0f;

		TestAssertEquals(v1, v2);
	};


	TEST_ADD_UNITTEST(OperatorMultiplyConstantReverseOrder)
	{
		Vector3 v1(5.0f, -9.0f, 14.0f);
		Vector3 v2(15.0f, -27.0f, 42.0f);

		TestAssertEquals(3.0f * v1, v2);
	};


	TEST_ADD_UNITTEST(OperatorDivisionConstant)
	{
		Vector3 v1(15.0f, -27.0f, 42.0f);
		Vector3 v2(5.0f, -9.0f, 14.0f);

		TestAssertEquals(v1 / 3.0f, v2);
	};


	TEST_ADD_UNITTEST(OperatorDivisionEqualConstant)
	{
		Vector3 v1(15.0f, -27.0f, 42.0f);
		Vector3 v2(5.0f, -9.0f, 14.0f);

		v1 /= 3.0f;

		TestAssertEquals(v1, v2);
	};


	TEST_ADD_UNITTEST(Cross)
	{
		Vector3 v1(3.0f, 5.0f, -9.0f);
		Vector3 v2(2.0f, -4.0f, 8.0f);
		Vector3 v3(4.0f, -42.0f, -22.0f);

		TestAssertEquals(Vector3::Cross(v1, v2), v3);
	};


	TEST_ADD_UNITTEST(Dot)
	{
		Vector3 v1(3.0f, 5.0f, -9.0f);
		Vector3 v2(2.0f, -4.0f, 8.0f);

		TestAssertEquals(Vector3::Dot(v1, v2), -86.0f);
	};


	TEST_ADD_UNITTEST(HadamardProduct)
	{
		Vector3 v1(3.0f, 5.0f, -9.0f);
		Vector3 v2(2.0f, -4.0f, 8.0f);
		Vector3 v3(6.0f, -20.0f, -72.0f);

		TestAssertEquals(Vector3::HadamardProduct(v1, v2), v3);
	};


	TEST_ADD_UNITTEST(HadamardDivision)
	{
		Vector3 v1(6.0f, -20.0f, -72.0f);
		Vector3 v2(2.0f, -4.0f, 8.0f);
		Vector3 v3(3.0f, 5.0f, -9.0f);

		TestAssertEquals(Vector3::HadamardDivision(v1, v2), v3);
	};


	TEST_ADD_UNITTEST(Normalize)
	{
		Vector3 v(5.0f, 9.0f, 14.0f);

		Vector3::Normalize(v);

		TestAssertEquals(v, Vector3(0.28771767f, 0.51789180f, 0.80560948f));
	};


	TEST_ADD_UNITTEST(Distance)
	{
		Vector3 v1(3.0f, 15.0f, -9.0f);
		Vector3 v2(-2.0f, 6.0f, -23.0f);

		TestAssertEquals(Vector3::Distance(v1, v2), 17.3781471f);
	};


	TEST_ADD_UNITTEST(AngleDeg)
	{
		Vector3 v1(2.0f, -4.0f, -1.0f);
		Vector3 v2(0.0f, 5.0f, 2.0f);

		TestAssertEquals(Vector3::AngleDeg(v1, v2), 153.0605011f);
	};


	TEST_ADD_UNITTEST(AngleRad)
	{
		Vector3 v1(2.0f, -4.0f, -1.0f);
		Vector3 v2(0.0f, 5.0f, 2.0f);

		TestAssertEquals(Vector3::AngleRad(v1, v2), 2.671408653f);
	};

	TEST_END_TESTMODULE(Vector3)
}

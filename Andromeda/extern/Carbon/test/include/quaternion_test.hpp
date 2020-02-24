#pragma once

#include <pulsar/test.hpp>
#include <carbon/quaternion.hpp>

namespace Carbon
{
	TEST_BEGIN_TESTMODULE(Quaternion)

	TEST_ADD_UNITTEST(ConstructorNoParameters)
	{
		Quaternion q;

		TestAssertEquals(q.X, 0.0f);
		TestAssertEquals(q.Y, 0.0f);
		TestAssertEquals(q.Z, 0.0f);
		TestAssertEquals(q.W, 1.0f);
	};


	TEST_ADD_UNITTEST(ConstructorWithParameters)
	{
		Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);

		TestAssertEquals(q.X, 1.0f);
		TestAssertEquals(q.Y, 2.0f);
		TestAssertEquals(q.Z, 3.0f);
		TestAssertEquals(q.W, 4.0f);
	};


	TEST_ADD_UNITTEST(OperatorEqualTrue)
	{
		Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion q2(1.0f, 2.0f, 3.0f, 4.0f);

		TestAssertEquals(q1 == q2, true);
	};


	TEST_ADD_UNITTEST(OperatorEqualFalse)
	{
		Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion q2(1.0f, 2.0f, 32.0f, 4.0f);

		TestAssertEquals(q1 == q2, false);
	};


	TEST_ADD_UNITTEST(OperatorNotEqualTrue)
	{
		Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion q2(1.0f, 2.0f, 32.0f, 4.0f);

		TestAssertEquals(q1 != q2, true);
	};


	TEST_ADD_UNITTEST(OperatorNotEqualFalse)
	{
		Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion q2(1.0f, 2.0f, 3.0f, 4.0f);

		TestAssertEquals(q1 != q2, false);
	};


	TEST_ADD_UNITTEST(StaticConst)
	{
		TestAssertEquals(Quaternion::IDENTITY, Quaternion(0.0f, 0.0f, 0.0f, 1.0f));
	};


	TEST_ADD_UNITTEST(ConstructorCopy)
	{
		Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);

		TestAssertEquals(Quaternion(q), q);
	};


	TEST_ADD_UNITTEST(GetEulerAnglesRad)
	{
		Quaternion q(0.4136909246f, 0.3732202947f, -0.1029267907f, 0.8239979148f);

		TestAssertEquals(q.GetEulerAnglesRad(), Vector3(0.872664988f, 0.785398066f, 0.1396259964f));
	};


	TEST_ADD_UNITTEST(GetEulerAnglesDeg)
	{
		Quaternion q(0.4136909246f, 0.3732202947f, -0.1029267907f, 0.8239979148f);

		TestAssertEquals(q.GetEulerAnglesDeg(), Vector3(50.0f, 45.0f, 8.0f));
	};


	TEST_ADD_UNITTEST(SetEulerAnglesRadWithVector)
	{
		Quaternion q;

		q.SetEulerAnglesRad(Vector3(0.872664988f, 0.785398066f, 0.1396259964f));

		TestAssertEquals(q, Quaternion(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f));
	};


	TEST_ADD_UNITTEST(SetEulerAnglesRadWithFloats)
	{
		Quaternion q;

		q.SetEulerAnglesRad(0.872664988f, 0.785398066f, 0.1396259964f);

		TestAssertEquals(q, Quaternion(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f));
	};


	TEST_ADD_UNITTEST(SetEulerAnglesDegWithVector)
	{
		Quaternion q;

		q.SetEulerAnglesDeg(Vector3(50.0f, 45.0f, 8.0f));

		TestAssertEquals(q, Quaternion(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f));
	};


	TEST_ADD_UNITTEST(SetEulerAnglesDegWithFloats)
	{
		Quaternion q;

		q.SetEulerAnglesDeg(50.0f, 45.0f, 8.0f);

		TestAssertEquals(q, Quaternion(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f));

		q.SetEulerAnglesDeg(0.0f, 90.0f, 0.0f);

		TestAssertEquals(q, Quaternion(0.0f, 0.7071067811865476f, 0.0f, 0.7071067811865476f));

		q.SetEulerAnglesDeg(0.0f, -90.0f, 0.0f);

		TestAssertEquals(q, Quaternion(0.0f, -0.7071067811865476f, 0.0f, 0.7071067811865476f));
	};


	TEST_ADD_UNITTEST(Inverse)
	{
		Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);

		TestAssertEquals(q.Inverse(), Quaternion(-1.0f, -2.0f, -3.0f, 4.0f));
	};


	TEST_ADD_UNITTEST(ToMatrix)
	{
		Quaternion q(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f);

		TestAssertEquals(q.ToMatrix(), Matrix3x4(0.7002254f, 0.4784186f, 0.5299057f, 0.0f,
			0.1391727f, 0.6365318f, -0.7585896f, 0.0f,
			-0.7002252f, 0.6049321f, 0.3791329f, 0.0f));
	};


	TEST_ADD_UNITTEST(OperatorBracket)
	{
		Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);

		TestAssertEquals(q[0], 1.0f);
		TestAssertEquals(q[1], 2.0f);
		TestAssertEquals(q[2], 3.0f);
		TestAssertEquals(q[3], 4.0f);
	};


	TEST_ADD_UNITTEST(OperatorMultiplyQuaternion)
	{
		Quaternion q1(2.0f, 3.0f, 4.0f, 1.0f);
		Quaternion q2(6.0f, 7.0f, 8.0f, 5.0f);

		TestAssertEquals(q1 * q2, Quaternion(12.0f, 30.0f, 24.0f, -60.0f));
	};


	TEST_ADD_UNITTEST(OperatorMultiplyVector)
	{
		Quaternion q1(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f);

		Vector3 v1 = Vector3(1.0f, 2.0f, 3.0f).Normalized();

		TestAssertEquals(q1 * v1, Vector3(0.8677383065f, -0.2307887822f, 0.4401893914f));

		Quaternion q2(0.0f, 0.7071067811865476f, 0.0f, 0.7071067811865476f);

		Vector3 v2 = Vector3(1.0f, 0.0f, 0.0f);

		TestAssertEquals(q2 * v2, Vector3(0.0f, 0.0f, -1.0f));

		Quaternion q3 = Quaternion::FromEulerAnglesDeg(0.0f, 0.0f, 45.0f);

		Vector3 v3 = Vector3(1.0f, 0.0f, 0.0f);

		TestAssertEquals(q3 * v3, Vector3(0.7071067811865476f, 0.7071067811865476f, 0.0f));
	};


	TEST_ADD_UNITTEST(OperatorMultiplyConstant)
	{
		Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);

		TestAssertEquals(q * 3.0f, Quaternion(3.0f, 6.0f, 9.0f, 12.0f));
	};


	TEST_ADD_UNITTEST(OperatorMultiplyEqualConstant)
	{
		Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);

		q *= 3.0f;

		TestAssertEquals(q, Quaternion(3.0f, 6.0f, 9.0f, 12.0f));
	};


	TEST_ADD_UNITTEST(Normalize)
	{
		Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);

		Quaternion::Normalize(q1);

		TestAssertEquals(q1, Quaternion(1.0f / 5.47722557f, 2.0f / 5.47722557f, 3.0f / 5.47722557f, 4.0f / 5.47722557f));

		Quaternion q2(0.0f, 0.0f, 0.0f, 0.0f);

		Quaternion::Normalize(q2);

		TestAssertEquals(q2, Quaternion::IDENTITY);
	};


	TEST_ADD_UNITTEST(RotationBetween)
	{
		Vector3 v1(1.0f, 0.0f, 0.0f);

		Vector3 v2(-1.0f, 0.0f, 0.0f);

		Vector3 v3(0.7071067811865476f, 0.7071067811865476f, 0.0f);

		TestAssertEquals(Quaternion::RotationBetween(v1, v1), Quaternion::IDENTITY);

		TestAssertEquals(Quaternion::RotationBetween(v1, v2), Quaternion(0.0f, 1.0f, 0.0f, 0.0f));

		TestAssertEquals(Quaternion::RotationBetween(v1, v3), Quaternion::FromEulerAnglesDeg(0.0f, 0.0f, 45.0f));
	};


	TEST_ADD_UNITTEST(FromEulerAnglesRadVector)
	{
		TestAssertEquals(Quaternion::FromEulerAnglesRad(Vector3(0.872664988f, 0.785398066f, 0.1396259964f)), Quaternion(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f));
	};


	TEST_ADD_UNITTEST(FromEulerAnglesRadFloats)
	{
		TestAssertEquals(Quaternion::FromEulerAnglesRad(0.872664988f, 0.785398066f, 0.1396259964f), Quaternion(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f));
	};


	TEST_ADD_UNITTEST(FromEulerAnglesDegVector)
	{
		TestAssertEquals(Quaternion::FromEulerAnglesDeg(Vector3(50.0f, 45.0f, 8.0f)), Quaternion(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f));
	};


	TEST_ADD_UNITTEST(FromEulerAnglesDegFloats)
	{
		TestAssertEquals(Quaternion::FromEulerAnglesDeg(50.0f, 45.0f, 8.0f), Quaternion(0.4136909246f, 0.3732202945f, -0.1029268056f, 0.8239979148f));
	};

	TEST_END_TESTMODULE(Quaternion)
}

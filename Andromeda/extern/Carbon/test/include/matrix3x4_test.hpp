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

	TEST_END_TESTMODULE(Vector3)
}

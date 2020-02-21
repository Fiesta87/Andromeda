#pragma once

#include <pulsar/test.hpp>
#include <vector3.hpp>

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

	TEST_END_TESTMODULE(Vector3)
}

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

	TEST_END_TESTMODULE(Vector3)

	/*class Vector3Test
	{
	public:
		Vector3Test();
		~Vector3Test();

		static void Run(TestContext& testContext);

		static void TestConstructorNoParameters(TestContext& testContext);
		static void TestConstructorWithParameters(TestContext& testContext);
		static void TestOperatorEqualTrue(TestContext& testContext);
		static void TestOperatorEqualFalse(TestContext& testContext);
		static void TestOperatorNotEqualTrue(TestContext& testContext);
		static void TestOperatorNotEqualFalse(TestContext& testContext);
		static void TestStaticConst(TestContext& testContext);
		static void TestConstructorCopy(TestContext& testContext);
		static void TestMagnitude(TestContext& testContext);
		static void TestNormalized(TestContext& testContext);
		static void TestSqrMagnitude(TestContext& testContext);
		static void TestOperatorBracket(TestContext& testContext);
		static void TestOperatorAddition(TestContext& testContext);
		static void TestOperatorAdditionEqual(TestContext& testContext);
		static void TestOperatorSubtraction(TestContext& testContext);
		static void TestOperatorSubtractionEqual(TestContext& testContext);
		static void TestOperatorInverse(TestContext& testContext);
		static void TestOperatorMultiplyConstant(TestContext& testContext);
		static void TestOperatorMultiplyEqualConstant(TestContext& testContext);
		static void TestOperatorMultiplyConstantReverseOrder(TestContext& testContext);
		static void TestOperatorDivisionConstant(TestContext& testContext);
		static void TestOperatorDivisionEqualConstant(TestContext& testContext);
		static void TestCross(TestContext& testContext);
		static void TestDot(TestContext& testContext);
		static void TestHadamardProduct(TestContext& testContext);
		static void TestHadamardDivision(TestContext& testContext);
		static void TestNormalize(TestContext& testContext);
		static void TestDistance(TestContext& testContext);
		static void TestAngleDeg(TestContext& testContext);
		static void TestAngleRad(TestContext& testContext);
	};*/
}

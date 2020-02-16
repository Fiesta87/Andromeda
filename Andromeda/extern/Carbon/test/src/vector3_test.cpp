//#include <vector3_test.hpp>
//
//#include <iostream>
//#include <fstream>
//
//#include "../../TestEnvironment.h"
//#include "../../TestAssertion.h"
//#include "Maths/Vector3.h"
//
//
//Vector3Test::Vector3Test()
//{
//}
//
//
//Vector3Test::~Vector3Test()
//{
//}
//
//
//void Vector3Test::Run(TestContext& testContext)
//{
//	TestStartModule(testContext, "Vector3");
//
//	Vector3Test::TestConstructorNoParameters(testContext);
//	Vector3Test::TestConstructorWithParameters(testContext);
//	Vector3Test::TestOperatorEqualTrue(testContext);
//	Vector3Test::TestOperatorEqualFalse(testContext);
//	Vector3Test::TestOperatorNotEqualTrue(testContext);
//	Vector3Test::TestOperatorNotEqualFalse(testContext);
//	Vector3Test::TestStaticConst(testContext);
//	Vector3Test::TestConstructorCopy(testContext);
//	Vector3Test::TestMagnitude(testContext);
//	Vector3Test::TestNormalized(testContext);
//	Vector3Test::TestSqrMagnitude(testContext);
//	Vector3Test::TestOperatorBracket(testContext);
//	Vector3Test::TestOperatorAddition(testContext);
//	Vector3Test::TestOperatorAdditionEqual(testContext);
//	Vector3Test::TestOperatorSubtraction(testContext);
//	Vector3Test::TestOperatorSubtractionEqual(testContext);
//	Vector3Test::TestOperatorInverse(testContext);
//	Vector3Test::TestOperatorMultiplyConstant(testContext);
//	Vector3Test::TestOperatorMultiplyEqualConstant(testContext);
//	Vector3Test::TestOperatorMultiplyConstantReverseOrder(testContext);
//	Vector3Test::TestOperatorDivisionConstant(testContext);
//	Vector3Test::TestOperatorDivisionEqualConstant(testContext);
//	Vector3Test::TestCross(testContext);
//	Vector3Test::TestDot(testContext);
//	Vector3Test::TestHadamardProduct(testContext);
//	Vector3Test::TestHadamardDivision(testContext);
//	Vector3Test::TestNormalize(testContext);
//	Vector3Test::TestDistance(testContext);
//	Vector3Test::TestAngleDeg(testContext);
//	Vector3Test::TestAngleRad(testContext);
//
//	TestEndModule(testContext);
//}
//
//
//void Vector3Test::TestConstructorNoParameters(TestContext& testContext)
//{
//	Vector3 v;
//
//	AssertEqual(v.X, 0.0f);
//	AssertEqual(v.Y, 0.0f);
//	AssertEqual(v.Z, 0.0f);
//}
//
//
//void Vector3Test::TestConstructorWithParameters(TestContext& testContext)
//{
//	Vector3 v(1.0f, 2.0f, 3.0f);
//
//	AssertEqual(v.X, 1.0f);
//	AssertEqual(v.Y, 2.0f);
//	AssertEqual(v.Z, 3.0f);
//}
//
//
//void Vector3Test::TestOperatorEqualTrue(TestContext& testContext)
//{
//	Vector3 v1(1.0f, 2.0f, 3.0f);
//	Vector3 v2(1.0f, 2.0f, 3.0f);
//
//	AssertEqual(v1 == v2, true);
//}
//
//
//void Vector3Test::TestOperatorEqualFalse(TestContext& testContext)
//{
//	Vector3 v1(1.0f, 2.0f, 3.0f);
//	Vector3 v2(1.0f, 2.0f, 4.0f);
//
//	AssertEqual(v1 == v2, false);
//}
//
//
//void Vector3Test::TestOperatorNotEqualTrue(TestContext& testContext)
//{
//	Vector3 v1(1.0f, 0.0f, 3.0f);
//	Vector3 v2(1.0f, 2.0f, 3.0f);
//
//	AssertEqual(v1 != v2, true);
//}
//
//
//void Vector3Test::TestOperatorNotEqualFalse(TestContext& testContext)
//{
//	Vector3 v1(1.0f, 2.0f, 3.0f);
//	Vector3 v2(1.0f, 2.0f, 3.0f);
//
//	AssertEqual(v1 != v2, false);
//}
//
//
//void Vector3Test::TestStaticConst(TestContext& testContext)
//{
//	AssertEqual(Vector3::ZERO, Vector3(0.0f, 0.0f, 0.0f));
//	AssertEqual(Vector3::ONE, Vector3(1.0f, 1.0f, 1.0f));
//	AssertEqual(Vector3::FORWARD, Vector3(1.0f, 0.0f, 0.0f));
//	AssertEqual(Vector3::BACKWARD, Vector3(-1.0f, 0.0f, 0.0f));
//	AssertEqual(Vector3::UP, Vector3(0.0f, 1.0f, 0.0f));
//	AssertEqual(Vector3::DOWN, Vector3(0.0f, -1.0f, 0.0f));
//	AssertEqual(Vector3::RIGHT, Vector3(0.0f, 0.0f, 1.0f));
//	AssertEqual(Vector3::LEFT, Vector3(0.0f, 0.0f, -1.0f));
//}
//
//
//void Vector3Test::TestConstructorCopy(TestContext& testContext)
//{
//	Vector3 v(-61.0f, 15.1f, 216.165f);
//
//	AssertEqual(Vector3(v), v);
//}
//
//
//void Vector3Test::TestMagnitude(TestContext& testContext)
//{
//	Vector3 v(5.0f, 9.0f, 14.0f);
//
//	AssertEqual(v.Magnitude(), 17.3781471f);
//}
//
//
//void Vector3Test::TestNormalized(TestContext& testContext)
//{
//	Vector3 v(5.0f, 9.0f, 14.0f);
//
//	AssertEqual(v.Normalized(), Vector3(0.28771767f, 0.51789180f, 0.80560948f));
//}
//
//
//void Vector3Test::TestSqrMagnitude(TestContext& testContext)
//{
//	Vector3 v(5.0f, 9.0f, 14.0f);
//
//	AssertEqual(v.SqrMagnitude(), 302.0f);
//}
//
//
//void Vector3Test::TestOperatorBracket(TestContext& testContext)
//{
//	Vector3 v(5.0f, 9.0f, 14.0f);
//
//	AssertEqual(v[0], 5.0f);
//	AssertEqual(v[1], 9.0f);
//	AssertEqual(v[2], 14.0f);
//}
//
//
//void Vector3Test::TestOperatorAddition(TestContext& testContext)
//{
//	Vector3 v1(5.0f, 9.0f, 14.0f);
//	Vector3 v2(3.0f, -7.0f, 0.0f);
//	Vector3 v3(8.0f, 2.0f, 14.0f);
//
//	AssertEqual(v1 + v2, v3);
//}
//
//
//void Vector3Test::TestOperatorAdditionEqual(TestContext& testContext)
//{
//	Vector3 v1(5.0f, 9.0f, 14.0f);
//	Vector3 v2(3.0f, -7.0f, 0.0f);
//	Vector3 v3(8.0f, 2.0f, 14.0f);
//
//	v1 += v2;
//
//	AssertEqual(v1, v3);
//}
//
//
//void Vector3Test::TestOperatorSubtraction(TestContext& testContext)
//{
//	Vector3 v1(5.0f, 9.0f, 14.0f);
//	Vector3 v2(3.0f, -7.0f, 30.0f);
//	Vector3 v3(2.0f, 16.0f, -16.0f);
//
//	AssertEqual(v1 - v2, v3);
//}
//
//
//void Vector3Test::TestOperatorSubtractionEqual(TestContext& testContext)
//{
//	Vector3 v1(5.0f, 9.0f, 14.0f);
//	Vector3 v2(3.0f, -7.0f, 30.0f);
//	Vector3 v3(2.0f, 16.0f, -16.0f);
//
//	v1 -= v2;
//
//	AssertEqual(v1, v3);
//}
//
//
//void Vector3Test::TestOperatorInverse(TestContext& testContext)
//{
//	Vector3 v1(5.0f, -9.0f, 14.0f);
//	Vector3 v2(-5.0f, 9.0f, -14.0f);
//
//	AssertEqual(-v1, v2);
//}
//
//
//void Vector3Test::TestOperatorMultiplyConstant(TestContext& testContext)
//{
//	Vector3 v1(5.0f, -9.0f, 14.0f);
//	Vector3 v2(15.0f, -27.0f, 42.0f);
//
//	AssertEqual(v1 * 3.0f, v2);
//}
//
//
//void Vector3Test::TestOperatorMultiplyEqualConstant(TestContext& testContext)
//{
//	Vector3 v1(5.0f, -9.0f, 14.0f);
//	Vector3 v2(15.0f, -27.0f, 42.0f);
//
//	v1 *= 3.0f;
//
//	AssertEqual(v1, v2);
//}
//
//
//void Vector3Test::TestOperatorMultiplyConstantReverseOrder(TestContext& testContext)
//{
//	Vector3 v1(5.0f, -9.0f, 14.0f);
//	Vector3 v2(15.0f, -27.0f, 42.0f);
//
//	AssertEqual(3.0f * v1, v2);
//}
//
//
//void Vector3Test::TestOperatorDivisionConstant(TestContext& testContext)
//{
//	Vector3 v1(15.0f, -27.0f, 42.0f);
//	Vector3 v2(5.0f, -9.0f, 14.0f);
//
//	AssertEqual(v1 / 3.0f, v2);
//}
//
//
//void Vector3Test::TestOperatorDivisionEqualConstant(TestContext& testContext)
//{
//	Vector3 v1(15.0f, -27.0f, 42.0f);
//	Vector3 v2(5.0f, -9.0f, 14.0f);
//
//	v1 /= 3.0f;
//
//	AssertEqual(v1, v2);
//}
//
//
//void Vector3Test::TestCross(TestContext& testContext)
//{
//	Vector3 v1(3.0f, 5.0f, -9.0f);
//	Vector3 v2(2.0f, -4.0f, 8.0f);
//	Vector3 v3(4.0f, -42.0f, -22.0f);
//
//	AssertEqual(Vector3::Cross(v1, v2), v3);
//}
//
//
//void Vector3Test::TestDot(TestContext& testContext)
//{
//	Vector3 v1(3.0f, 5.0f, -9.0f);
//	Vector3 v2(2.0f, -4.0f, 8.0f);
//
//	AssertEqual(Vector3::Dot(v1, v2), -86.0f);
//}
//
//
//void Vector3Test::TestHadamardProduct(TestContext& testContext)
//{
//	Vector3 v1(3.0f, 5.0f, -9.0f);
//	Vector3 v2(2.0f, -4.0f, 8.0f);
//	Vector3 v3(6.0f, -20.0f, -72.0f);
//
//	AssertEqual(Vector3::HadamardProduct(v1, v2), v3);
//}
//
//
//void Vector3Test::TestHadamardDivision(TestContext& testContext)
//{
//	Vector3 v1(6.0f, -20.0f, -72.0f);
//	Vector3 v2(2.0f, -4.0f, 8.0f);
//	Vector3 v3(3.0f, 5.0f, -9.0f);
//
//	AssertEqual(Vector3::HadamardDivision(v1, v2), v3);
//}
//
//
//void Vector3Test::TestNormalize(TestContext& testContext)
//{
//	Vector3 v(5.0f, 9.0f, 14.0f);
//
//	Vector3::Normalize(v);
//
//	AssertEqual(v, Vector3(0.28771767f, 0.51789180f, 0.80560948f));
//}
//
//
//void Vector3Test::TestDistance(TestContext& testContext)
//{
//	Vector3 v1(3.0f, 15.0f, -9.0f);
//	Vector3 v2(-2.0f, 6.0f, -23.0f);
//
//	AssertEqual(Vector3::Distance(v1, v2), 17.3781471f);
//}
//
//
//void Vector3Test::TestAngleDeg(TestContext& testContext)
//{
//	Vector3 v1(2.0f, -4.0f, -1.0f);
//	Vector3 v2(0.0f, 5.0f, 2.0f);
//
//	AssertEqual(Vector3::AngleDeg(v1, v2), 153.0605011f);
//}
//
//
//void Vector3Test::TestAngleRad(TestContext& testContext)
//{
//	Vector3 v1(2.0f, -4.0f, -1.0f);
//	Vector3 v2(0.0f, 5.0f, 2.0f);
//
//	AssertEqual(Vector3::AngleRad(v1, v2), 2.671408653f);
//}
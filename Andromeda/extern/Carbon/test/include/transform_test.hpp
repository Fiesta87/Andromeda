#pragma once

#include <pulsar/test.hpp>
#include <carbon/transform.hpp>

namespace Carbon
{
	// mock class for Entity
	class Entity
	{};

	TEST_BEGIN_TESTMODULE(Transform)

	TEST_ADD_UNITTEST(ConstructorAndGetEntity)
	{
		Entity e;
		Transform t(e);

		//TestAssertEquals(&t.GetEntity(), &e);
		TestAssertEquals(t.GetPositionInLocalSpace(), Vector3::ZERO);
		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion::IDENTITY);
		TestAssertEquals(t.GetScaleInLocalSpace(), Vector3::ONE);
	};


	TEST_ADD_UNITTEST(GetSetPositionInLocalSpace)
	{
		Entity e;
		Transform t(e);

		t.SetPositionInLocalSpace(Vector3(42.0f, -19.0f, 3.14f));

		TestAssertEquals(t.GetPositionInLocalSpace(), Vector3(42.0f, -19.0f, 3.14f));
	};


	TEST_ADD_UNITTEST(GetSetRotationInLocalSpace)
	{
		Entity e;
		Transform t(e);

		t.SetRotationInLocalSpace(Quaternion(0.7071067811865476f, 0.0f, 0.0f, 0.7071067811865476f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.7071067811865476f, 0.0f, 0.0f, 0.7071067811865476f));
	};


	TEST_ADD_UNITTEST(GetSetRotationEulerAnglesDegInLocalSpace)
	{
		Entity e;
		Transform t(e);

		t.SetRotationEulerAnglesDegInLocalSpace(Vector3(10.0f, 20.0f, 30.0f));

		TestAssertEquals(t.GetRotationEulerAnglesDegInLocalSpace(), Vector3(10.0f, 20.0f, 30.0f));

		t.SetRotationEulerAnglesDegInLocalSpace(30.0f, 10.0f, 20.0f);

		TestAssertEquals(t.GetRotationEulerAnglesDegInLocalSpace(), Vector3(30.0f, 10.0f, 20.0f));
	};


	TEST_ADD_UNITTEST(GetSetRotationEulerAnglesRadInLocalSpace)
	{
		Entity e;
		Transform t(e);

		t.SetRotationEulerAnglesRadInLocalSpace(Vector3(0.174533f, 0.349066f, 0.523599f));

		TestAssertEquals(t.GetRotationEulerAnglesRadInLocalSpace(), Vector3(0.174533f, 0.349066f, 0.523599f));
		TestAssertEquals(t.GetRotationEulerAnglesDegInLocalSpace(), Vector3(10.0f, 20.0f, 30.0f));

		t.SetRotationEulerAnglesRadInLocalSpace(0.523599f, 0.174533f, 0.349066f);

		TestAssertEquals(t.GetRotationEulerAnglesRadInLocalSpace(), Vector3(0.523599f, 0.174533f, 0.349066f));
	};


	TEST_ADD_UNITTEST(GetSetScaleInLocalSpace)
	{
		Entity e;
		Transform t(e);

		t.SetScaleInLocalSpace(Vector3(2.0f, 3.0f, 4.0f));

		TestAssertEquals(t.GetScaleInLocalSpace(), Vector3(2.0f, 3.0f, 4.0f));

		t.SetScaleInLocalSpace(5.0f, 6.0f, 7.0f);

		TestAssertEquals(t.GetScaleInLocalSpace(), Vector3(5.0f, 6.0f, 7.0f));
	};


	TEST_ADD_UNITTEST(TranslateInLocalSpace)
	{
		Entity e;
		Transform t(e);

		t.TranslateInLocalSpace(Vector3(42.0f, -19.0f, 3.0f));

		TestAssertEquals(t.GetPositionInLocalSpace(), Vector3(42.0f, -19.0f, 3.0f));

		t.TranslateInLocalSpace(Vector3(9.0f, 2.0f, -13.0f));

		TestAssertEquals(t.GetPositionInLocalSpace(), Vector3(51.0f, -17.0f, -10.0f));

		t.TranslateInLocalSpace(-5.0f, 8.0f, 32.0f);

		TestAssertEquals(t.GetPositionInLocalSpace(), Vector3(46.0f, -9.0f, 22.0f));
	};


	TEST_ADD_UNITTEST(RotateRadInLocalSpace)
	{
		Entity e;
		Transform t(e);

		t.RotateRadInLocalSpace(Vector3(0.0f, 1.5708f, 0.0f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 0.70710f, 0.0f, 0.70710f));

		t.RotateRadInLocalSpace(0.0f, 1.5708f, 0.0f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 1.0f, 0.0f, 0.0f));

		t.RotateRadInLocalSpace(Vector3(0.785398f, 0.0f, 0.0f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 0.92388f, -0.38268f, 0.0f));

		t.RotateRadInLocalSpace(Vector3(0.0f, 0.0f, 0.785398f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.35355f, 0.85355f, -0.35355f, 0.14644f));

		t.RotateRadInLocalSpace(Vector3(0.0f, 0.0f, 0.0f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.35355f, 0.85355f, -0.35355f, 0.14644f));

		t.SetRotationInLocalSpace(Quaternion::IDENTITY);

		t.RotateRadInLocalSpace(0.785398f, 3.14159f, 0.785398f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.35355f, 0.85355f, -0.35355f, -0.14644f));
	};


	TEST_ADD_UNITTEST(RotateRadInLocalSpaceAroundSpecificAxis)
	{
		Entity e;
		Transform t(e);

		t.RotateRadInLocalSpaceAroundAxisY(3.14159f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 1.0f, 0.0f, 0.0f));

		t.RotateRadInLocalSpaceAroundAxisX(0.785398f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 0.92388f, -0.38268f, 0.0f));

		t.RotateRadInLocalSpaceAroundAxisZ(0.785398f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.35355f, 0.85355f, -0.35355f, 0.14644f));
	};


	TEST_ADD_UNITTEST(RotateDegInLocalSpace)
	{
		Entity e;
		Transform t(e);

		t.RotateDegInLocalSpace(Vector3(0.0f, 90.0f, 0.0f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 0.70710f, 0.0f, 0.70710f));

		t.RotateDegInLocalSpace(0.0f, 90.0f, 0.0f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 1.0f, 0.0f, 0.0f));

		t.RotateDegInLocalSpace(Vector3(45.0f, 0.0f, 0.0f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 0.92388f, -0.38268f, 0.0f));

		t.RotateDegInLocalSpace(Vector3(0.0f, 0.0f, 45.0f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.35355f, 0.85355f, -0.35355f, 0.14644f));

		t.RotateDegInLocalSpace(Vector3(0.0f, 0.0f, 0.0f));

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.35355f, 0.85355f, -0.35355f, 0.14644f));

		t.SetRotationInLocalSpace(Quaternion::IDENTITY);

		t.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.35355f, 0.85355f, -0.35355f, -0.14644f));
	};


	TEST_ADD_UNITTEST(RotateDegInLocalSpaceAroundSpecificAxis)
	{
		Entity e;
		Transform t(e);

		t.RotateDegInLocalSpaceAroundAxisY(180.0f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 1.0f, 0.0f, 0.0f));

		t.RotateDegInLocalSpaceAroundAxisX(45.0f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.0f, 0.92388f, -0.38268f, 0.0f));

		t.RotateDegInLocalSpaceAroundAxisZ(45.0f);

		TestAssertEquals(t.GetRotationInLocalSpace(), Quaternion(0.35355f, 0.85355f, -0.35355f, 0.14644f));
	};


	TEST_ADD_UNITTEST(GetLocalTransformMatrix)
	{
		Entity e;
		Transform t(e);

		TestAssertEquals(t.GetLocalTransformMatrix(), Matrix3x4::IDENTITY);

		t.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		TestAssertEquals(t.GetLocalTransformMatrix(), Matrix3x4(-0.7071118f, 0.5000038f, -0.4999892f, 0.0f,
			0.7071018f, 0.5000033f, -0.5000038f, 0.0f,
			-0.0000075f, -0.7071018f, -0.7071118f, 0.0f));

		t.TranslateInLocalSpace(20.0f, 40.0f, 60.0f);

		TestAssertEquals(t.GetLocalTransformMatrix(), Matrix3x4(-0.7071118f, 0.5000038f, -0.4999892f, 20.0f,
			0.7071018f, 0.5000033f, -0.5000038f, 40.0f,
			-0.0000075f, -0.7071018f, -0.7071118f, 60.0f));

		t.SetScaleInLocalSpace(2.0f, 4.0f, 6.0f);

		TestAssertEquals(t.GetLocalTransformMatrix(), Matrix3x4(-1.4142236f, 2.0000152f, -2.9999352f, 20.0f,
			1.4142036f, 2.0000132f, -3.0000228f, 40.0f,
			-0.0000150f, -2.8284072f, -4.2426708f, 60.0f));
	};


	TEST_ADD_UNITTEST(GetWorldTransformMatrix)
	{
		Entity e1;
		Transform t1(e1);

		t1.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(20.0f, 40.0f, 60.0f);

		t1.SetScaleInLocalSpace(2.0f, 4.0f, 6.0f);

		TestAssertEquals(t1.GetWorldTransformMatrix(), Matrix3x4(-1.4142236f, 2.0000152f, -2.9999352f, 20.0f,
			1.4142036f, 2.0000132f, -3.0000228f, 40.0f,
			-0.0000150f, -2.8284072f, -4.2426708f, 60.0f));

		Entity e2;
		Transform t2(e2, &t1);

		TestAssertEquals(t2.GetParentEntity(), &e1);

		TestAssertEquals(t2.GetParentTransform(), &t1);

		TestAssertEquals(t1.GetChildrenTransform().size(), size_t(1));

		TestAssertEquals(t1.GetChildTransform(0), &t2);

		TestAssertEquals(t2.GetLocalTransformMatrix(), Matrix3x4::IDENTITY);

		TestAssertEquals(t2.GetWorldTransformMatrix(), Matrix3x4(-1.4142236f, 2.0000152f, -2.9999352f, 20.0f,
			1.4142036f, 2.0000132f, -3.0000228f, 40.0f,
			-0.0000150f, -2.8284072f, -4.2426708f, 60.0f));

		t2.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		TestAssertEquals(t2.GetLocalTransformMatrix(), Matrix3x4(-0.7071118f, 0.5000038f, -0.4999892f, 0.0f,
			0.7071018f, 0.5000033f, -0.5000038f, 0.0f,
			-0.0000075f, -0.7071018f, -0.7071118f, 0.0f));

		TestAssertEquals(t2.GetWorldTransformMatrix(), Matrix3x4(1.707103491f, 1.00000596f, 2.742649078f, -24.14223862f,
			-0.2928940654f, 3.828424931f, -1.500007868f, 4.142127991f,
			-1.000004053f, 0.585786581f, 5.121310234f, -70.71062469f));

		t1.TranslateInLocalSpace(8.0f, 15.0f, -3.0f);

		TestAssertEquals(t2.GetWorldTransformMatrix(), Matrix3x4(1.707103491f, 1.00000596f, 2.742649078f, -20.79909897f,
			-0.2928940654f, 3.828424931f, -1.500007868f, 18.7989769f,
			-1.000004053f, 0.585786581f, 5.121310234f, -79.19591522f));
	};


	TEST_ADD_UNITTEST(GetSetPositionInWorldSpace)
	{
		Entity e1;
		Transform t1(e1);

		t1.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(20.0f, 40.0f, 60.0f);

		t1.SetScaleInLocalSpace(2.0f, 4.0f, 6.0f);

		Entity e2;
		Transform t2(e2, &t1);

		t2.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(8.0f, 15.0f, -3.0f);

		TestAssertEquals(t2.GetWorldTransformMatrix(), Matrix3x4(1.707103491f, 1.00000596f, 2.742649078f, -20.79909897f,
			-0.2928940654f, 3.828424931f, -1.500007868f, 18.7989769f,
			-1.000004053f, 0.585786581f, 5.121310234f, -79.19591522f));

		Entity e3;
		Transform t3(e3, &t2);

		t3.SetPositionInWorldSpace(Vector3(61.6f, 65.164f, 16.416f));

		TestAssertEquals(t3.GetPositionInWorldSpace(), Vector3(61.6f, 65.164f, 16.416f));

		t3.SetPositionInWorldSpace(-20.79909897f, 18.7989769f, -79.19591522f);

		TestAssertEquals(t3.GetPositionInLocalSpace(), Vector3::ZERO);

		TestAssertEquals(t3.GetPositionInWorldSpace(), Vector3(-20.79909897f, 18.7989769f, -79.19591522f));

		t3.SetPositionInWorldSpace(Vector3(5.0f, 6.0f, -15.0f));

		TestAssertEquals(t3.GetPositionInWorldSpace(), Vector3(5.0f, 6.0f, -15.0f));
	};


	TEST_ADD_UNITTEST(GetSetRotationInWorldSpace)
	{
		Entity e1;
		Transform t1(e1);

		t1.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(20.0f, 40.0f, 60.0f);

		t1.SetScaleInLocalSpace(2.0f, 4.0f, 6.0f);

		Entity e2;
		Transform t2(e2, &t1);

		t2.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(8.0f, 15.0f, -3.0f);

		TestAssertEquals(t2.GetRotationInWorldSpace(), Quaternion(-0.1035538316f, -0.2500010729f, 0.1035539508f, -0.9571062922f));

		Entity e3;
		Transform t3(e3, &t2);

		t3.SetRotationInWorldSpace(Quaternion(-0.763f, 0.296f, -0.314f, 0.482f));

		TestAssertEquals(t3.GetRotationInWorldSpace(), Quaternion(-0.763f, 0.296f, -0.314f, 0.482f));

		t3.SetRotationInWorldSpace(Quaternion(-0.1035538316f, -0.2500010729f, 0.1035539508f, -0.9571062922f));

		TestAssertEquals(t3.GetRotationInLocalSpace(), Quaternion::IDENTITY);

		TestAssertEquals(t3.GetRotationInWorldSpace(), Quaternion(-0.1035538316f, -0.2500010729f, 0.1035539508f, -0.9571062922f));

		Entity e4;
		Transform t4(e4, &t2);

		t4.SetRotationEulerAnglesRadInWorldSpace(0.2554967105f, 0.5299052f, -0.1469757259f);

		TestAssertEquals(t4.GetRotationEulerAnglesRadInLocalSpace(), Vector3::ZERO);

		TestAssertEquals(t4.GetRotationEulerAnglesRadInWorldSpace(), Vector3(0.2554967105f, 0.5299052f, -0.1469757259f));

		t4.SetRotationEulerAnglesRadInWorldSpace(Vector3(0.2554967105f, 0.5299052f, -0.1469757259f));

		TestAssertEquals(t4.GetRotationEulerAnglesRadInLocalSpace(), Vector3::ZERO);

		Entity e5;
		Transform t5(e5, &t2);

		t5.SetRotationEulerAnglesDegInWorldSpace(14.63889503f, 30.36135483f, -8.421095848f);

		TestAssertEquals(t5.GetRotationEulerAnglesDegInLocalSpace(), Vector3::ZERO);

		TestAssertEquals(t5.GetRotationEulerAnglesDegInWorldSpace(), Vector3(14.63889503f, 30.36135483f, -8.421095848f));

		t5.SetRotationEulerAnglesDegInWorldSpace(Vector3(14.63889503f, 30.36135483f, -8.421095848f));

		TestAssertEquals(t5.GetRotationEulerAnglesDegInLocalSpace(), Vector3::ZERO);
	};


	TEST_ADD_UNITTEST(GetSetScaleInWorldSpace)
	{
		Entity e1;
		Transform t1(e1);

		t1.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(20.0f, 40.0f, 60.0f);

		t1.SetScaleInLocalSpace(2.0f, 4.0f, 6.0f);

		Entity e2;
		Transform t2(e2, &t1);

		t2.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(8.0f, 15.0f, -3.0f);

		TestAssertEquals(t2.GetScaleInWorldSpace(), Vector3(2.0f, 4.0f, 6.0f));

		Entity e3;
		Transform t3(e3, &t2);

		t3.SetScaleInWorldSpace(10.0f, 8.0f, 3.0f);

		TestAssertEquals(t3.GetScaleInLocalSpace(), Vector3(5.0f, 2.0f, 0.5f));

		TestAssertEquals(t3.GetScaleInWorldSpace(), Vector3(10.0f, 8.0f, 3.0f));

		t3.SetScaleInWorldSpace(Vector3(3.0f, 2.0f, 6.0f));

		TestAssertEquals(t3.GetScaleInLocalSpace(), Vector3(1.5f, 0.5f, 1.0f));
	};


	TEST_ADD_UNITTEST(TranslateInWorldSpace)
	{
		Entity e1;
		Transform t1(e1);

		t1.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(20.0f, 40.0f, 60.0f);

		t1.SetScaleInLocalSpace(2.0f, 4.0f, 6.0f);

		Entity e2;
		Transform t2(e2, &t1);

		t2.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(8.0f, 15.0f, -3.0f);

		TestAssertEquals(t2.GetWorldTransformMatrix(), Matrix3x4(1.707103491f, 1.00000596f, 2.742649078f, -20.79909897f,
			-0.2928940654f, 3.828424931f, -1.500007868f, 18.7989769f,
			-1.000004053f, 0.585786581f, 5.121310234f, -79.19591522f));

		Entity e3;
		Transform t3(e3, &t2);

		t3.TranslateInWorldSpace(Vector3(-3.0f, 5.0f, 1.0f));

		TestAssertEquals(t3.GetPositionInWorldSpace(), Vector3(-23.79909897f, 23.7989769f, -78.19591522f));

		t3.TranslateInWorldSpace(Vector3(15.0f, 8.0f, 38.0f));

		TestAssertEquals(t3.GetPositionInWorldSpace(), Vector3(-8.79909897f, 31.7989769f, -40.19591522f));

		Entity e4;
		Transform t4(e4);

		t4.TranslateInWorldSpace(5.0f, 3.0f, 2.0f);

		TestAssertEquals(t4.GetPositionInWorldSpace(), Vector3(5.0f, 3.0f, 2.0f));

		t4.TranslateInWorldSpace(9.0f, -4.0f, 8.0f);

		TestAssertEquals(t4.GetPositionInWorldSpace(), Vector3(14.0f, -1.0f, 10.0f));
	};


	TEST_ADD_UNITTEST(TranslateRelativeTo)
	{
		Entity e1;
		Transform t1(e1);

		t1.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(20.0f, 40.0f, 60.0f);

		t1.SetScaleInLocalSpace(2.0f, 4.0f, 6.0f);

		Entity e2;
		Transform t2(e2, &t1);

		t2.RotateDegInLocalSpace(45.0f, 180.0f, 45.0f);

		t1.TranslateInLocalSpace(8.0f, 15.0f, -3.0f);

		TestAssertEquals(t2.GetWorldTransformMatrix(), Matrix3x4(1.707103491f, 1.00000596f, 2.742649078f, -20.79909897f,
			-0.2928940654f, 3.828424931f, -1.500007868f, 18.7989769f,
			-1.000004053f, 0.585786581f, 5.121310234f, -79.19591522f));

		Entity e3;
		Transform t3(e3);

		t3.SetRotationEulerAnglesDegInLocalSpace(90.0f, 0.0f, 0.0f);

		Entity e4;
		Transform t4(e4, &t2);

		t4.TranslateRelativeTo(Vector3(-3.0f, 5.0f, 1.0f), t3);

		TestAssertEquals(t4.GetPositionInWorldSpace(), Vector3(-23.79909897f, 17.7989769f, -74.19591522f));

		t3.SetRotationEulerAnglesDegInLocalSpace(0.0f, 180.0f, 0.0f);

		t4.TranslateRelativeTo(8.0f, 4.0f, -7.0f, t3);

		TestAssertEquals(t4.GetPositionInWorldSpace(), Vector3(-31.79909897f, 21.7989769f, -67.19591522f));

		t3.SetScaleInLocalSpace(2.0f, 3.0f, 4.0f);

		t4.TranslateRelativeTo(Vector3(8.0f, 4.0f, -7.0f), t3);

		TestAssertEquals(t4.GetPositionInWorldSpace(), Vector3(-47.79909897f, 33.7989769f, -39.19591522f));
	};


	TEST_ADD_UNITTEST(RotateInWorldSpace)
	{
		Entity e1;
		Transform t1(e1);

		t1.RotateDegInWorldSpace(90.0f, 0.0f, 0.0f);

		TestAssertEquals(t1.GetRotationEulerAnglesDegInWorldSpace(), Vector3(90.0f, 0.0f, 0.0f));

		t1.RotateDegInWorldSpace(Vector3(90.0f, 0.0f, 0.0f));

		TestAssertEquals(t1.GetRotationEulerAnglesDegInWorldSpace(), Vector3(-180.0f, 0.0f, 0.0f));

		Entity e2;
		Transform t2(e2, &t1);

		TestAssertEquals(t2.GetRotationEulerAnglesDegInWorldSpace(), Vector3(-180.0f, 0.0f, 0.0f));

		t2.RotateRadInWorldSpace(0.0f, 1.570797f, 0.0f);

		TestAssertEquals(t2.GetRotationEulerAnglesDegInLocalSpace(), Vector3(0.0f, -90.0f, 0.0f));

		t2.RotateRadInWorldSpace(Vector3(0.0f, 1.570797f, 0.0f));

		TestAssertEquals(t2.GetRotationEulerAnglesDegInLocalSpace(), Vector3(0.0f, 180.0f, 0.0f));

		Entity e3;
		Transform t3(e3, &t1);

		t3.RotateRadInWorldSpaceAroundAxisX(1.570797f);

		TestAssertEquals(t3.GetRotationEulerAnglesDegInLocalSpace(), Vector3(90.0f, 0.0f, 0.0f));

		Entity e4;
		Transform t4(e4, &t1);

		t4.RotateRadInWorldSpaceAroundAxisY(1.570797f);

		TestAssertEquals(t4.GetRotationEulerAnglesDegInLocalSpace(), Vector3(0.0f, -90.0f, 0.0f));

		Entity e5;
		Transform t5(e5, &t1);

		t5.RotateRadInWorldSpaceAroundAxisZ(1.570797f);

		TestAssertEquals(t5.GetRotationEulerAnglesDegInLocalSpace(), Vector3(0.0f, 0.0f, -89.9515f));

		Entity e6;
		Transform t6(e6, &t1);

		t6.RotateDegInWorldSpaceAroundAxisX(90.0f);

		TestAssertEquals(t6.GetRotationEulerAnglesDegInLocalSpace(), Vector3(90.0f, 0.0f, 0.0f));

		Entity e7;
		Transform t7(e7, &t1);

		t7.RotateDegInWorldSpaceAroundAxisY(90.0f);

		TestAssertEquals(t7.GetRotationEulerAnglesDegInLocalSpace(), Vector3(0.0f, -90.0f, 0.0f));

		Entity e8;
		Transform t8(e8, &t1);

		t8.RotateDegInWorldSpaceAroundAxisZ(90.0f);

		TestAssertEquals(t8.GetRotationEulerAnglesDegInLocalSpace(), Vector3(0.0f, 0.0f, -89.9515f));
	};


	TEST_ADD_UNITTEST(DirectionAxis)
	{
		Entity e1;
		Transform t1(e1);

		TestAssertEquals(t1.GetForward(), Vector3::FORWARD);
		TestAssertEquals(t1.GetBackward(), Vector3::BACKWARD);
		TestAssertEquals(t1.GetUp(), Vector3::UP);
		TestAssertEquals(t1.GetDown(), Vector3::DOWN);
		TestAssertEquals(t1.GetRight(), Vector3::RIGHT);
		TestAssertEquals(t1.GetLeft(), Vector3::LEFT);

		t1.RotateDegInLocalSpace(90.0f, 0.0f, 0.0f);

		TestAssertEquals(t1.GetForward(), Vector3::FORWARD);
		TestAssertEquals(t1.GetBackward(), Vector3::BACKWARD);
		TestAssertEquals(t1.GetUp(), Vector3::RIGHT);
		TestAssertEquals(t1.GetDown(), Vector3::LEFT);
		TestAssertEquals(t1.GetRight(), Vector3::DOWN);
		TestAssertEquals(t1.GetLeft(), Vector3::UP);

		Entity e2(e1);
		Transform t2(e2, &t1);

		TestAssertEquals(t2.GetForward(), Vector3::FORWARD);
		TestAssertEquals(t2.GetBackward(), Vector3::BACKWARD);
		TestAssertEquals(t2.GetUp(), Vector3::RIGHT);
		TestAssertEquals(t2.GetDown(), Vector3::LEFT);
		TestAssertEquals(t2.GetRight(), Vector3::DOWN);
		TestAssertEquals(t2.GetLeft(), Vector3::UP);

		t1.RotateDegInLocalSpace(0.0f, 90.0f, 0.0f);

		TestAssertEquals(t2.GetForward(), Vector3::UP);
		TestAssertEquals(t2.GetBackward(), Vector3::DOWN);
		TestAssertEquals(t2.GetUp(), Vector3::RIGHT);
		TestAssertEquals(t2.GetDown(), Vector3::LEFT);
		TestAssertEquals(t2.GetRight(), Vector3::FORWARD);
		TestAssertEquals(t2.GetLeft(), Vector3::BACKWARD);
	};


	TEST_ADD_UNITTEST(ComplexeScene)
	{
		Entity e;
		Transform t(e);

		t.SetPositionInLocalSpace(1.0f, 2.0f, 3.0f);

		TestAssertEquals(t.GetPositionInLocalSpace(), Vector3(1.0f, 2.0f, 3.0f));
		TestAssertEquals(t.GetPositionInWorldSpace(), Vector3(1.0f, 2.0f, 3.0f));

		t.RotateDegInLocalSpaceAroundAxisY(90.0f);

		TestAssertEquals(t.GetPositionInLocalSpace(), Vector3(1.0f, 2.0f, 3.0f));
		TestAssertEquals(t.GetPositionInWorldSpace(), Vector3(1.0f, 2.0f, 3.0f));
	};

	TEST_END_TESTMODULE(Transform)
}

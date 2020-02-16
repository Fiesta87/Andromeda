#pragma once

#include <carbon.hpp>

#include <iostream>

namespace Carbon
{
	class Vector3;
	class Matrix3x4;


	////////////////////////////////////////////////////////////////////////////////
	// Quaternion
	////////////////////////////////////////////////////////////////////////////////
	class Quaternion
	{

	public:
		static const Quaternion IDENTITY;	// (0, 0, 0, 1)

	public:
		Quaternion(float X = 0.0f, float Y = 0.0f, float Z = 0.0f, float W = 1.0f);
		Quaternion(const Quaternion& other);
		~Quaternion();

	public:
		Vector3 GetEulerAnglesRad() const;

		Vector3 GetEulerAnglesDeg() const;

		void SetEulerAnglesRad(float x, float y, float z);

		void SetEulerAnglesRad(const Vector3& eulerAngles);

		void SetEulerAnglesDeg(float x, float y, float z);

		void SetEulerAnglesDeg(const Vector3& eulerAngles);

		inline Quaternion Inverse() const { return Quaternion(-X, -Y, -Z, W); }	// assuming quaternion is normalized,  q* = q(-1)

		Matrix3x4 ToMatrix() const;

	public:
		bool operator == (const Quaternion& other) const;

		bool operator != (const Quaternion& other) const;

		float& operator [] (int index);

		friend std::ostream& operator << (std::ostream& os, const Quaternion& quaternion);

		Quaternion operator * (const Quaternion& other) const;

		Vector3 operator * (const Vector3& vector) const;

		Quaternion operator * (float k) const;

		Quaternion& operator *= (float k);

	public:
		static void Normalize(Quaternion& quaternion);

		static Quaternion RotationBetween(const Vector3& from, const Vector3& to);

		static Quaternion FromEulerAnglesRad(const Vector3& eulerAngles);

		static Quaternion FromEulerAnglesRad(float x, float y, float z);

		static Quaternion FromEulerAnglesDeg(const Vector3& eulerAngles);

		static Quaternion FromEulerAnglesDeg(float x, float y, float z);

	public:
		float X;
		float Y;
		float Z;
		float W;
	};
}

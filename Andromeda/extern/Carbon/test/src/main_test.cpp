#include <pulsar/test.hpp>

#include <vector3_test.hpp>
#include <matrix3x4_test.hpp>

int main(int argc, char* argv[])
{
	TEST_BEGIN_TESTSUITE(Carbon);

	TEST_ADD_TESTMODULE(Vector3, Carbon);

	TEST_ADD_TESTMODULE(Matrix3x4, Carbon);

	TEST_END_TESTSUITE(Carbon);
}
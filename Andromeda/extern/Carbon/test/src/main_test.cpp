#include <testframework.hpp>

#include <vector3_test.hpp>

int main(int argc, char* argv[])
{
	TEST_BEGIN_TESTSUITE(Carbon);

	TEST_ADD_TESTMODULE(Vector3, Carbon);

	TEST_END_TESTSUITE(Carbon);
}
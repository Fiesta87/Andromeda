#pragma once

#include <vector>

#include <pulsar/logger.hpp>

//////////////////////////////////
// TEST SUITE GENERATION MACROS //
//////////////////////////////////

#define TEST_BEGIN_TESTSUITE(suiteName)	TEST_BEGIN_TESTSUITE_LOGCONF(suiteName, Pulsar::TestLogLevel::All)
#define TEST_BEGIN_TESTSUITE_LOGCONF(suiteName, logLevels)	Pulsar::TestSuite suiteName##TestSuite(#suiteName, logLevels)

#define TEST_END_TESTSUITE(suiteName) \
suiteName##TestSuite.Run();\
return suiteName##TestSuite.m_failureCount;


///////////////////////////////////
// TEST MODULE GENERATION MACROS //
///////////////////////////////////

#define TEST_BEGIN_TESTMODULE(moduleName) \
class moduleName##Tests : public Pulsar::TestModule\
{\
public:\
	moduleName##Tests(Pulsar::TestSuite* suite)\
		: Pulsar::TestModule(suite, #moduleName)\
	{


#define TEST_END_TESTMODULE(moduleName)	\
	}\
};


#define TEST_ADD_TESTMODULE(moduleName, suiteName)	\
suiteName::moduleName##Tests moduleName##TestModule(&suiteName##TestSuite);\
suiteName##TestSuite.AddTestModule(moduleName##TestModule)


/////////////////////////////////
// UNIT TEST GENERATION MACROS //
/////////////////////////////////

#define TEST_ADD_UNITTEST(testName) \
Pulsar::UnitTest test##testName(#testName, this);\
m_tests.push_back(test##testName);\
m_tests[m_tests.size()-1].m_func = [](Pulsar::UnitTest* test_ctx)->void


//////////////////////////////////////
// TEST ASSERTION GENERATION MACROS //
//////////////////////////////////////

#define TestAssert(condition) \
test_ctx->m_testCount++;\
if(!(condition))\
{\
	test_ctx->Logger().Log(MakeLogLevel(Pulsar::TestLogLevel::UnitTestFailure), "			Unit Test \"", test_ctx->GetName(), "\" FAIL"); \
	test_ctx->m_failureCount++;\
}\
else\
	test_ctx->Logger().Log(MakeLogLevel(Pulsar::TestLogLevel::UnitTestSuccess), "			Unit Test \"", test_ctx->GetName(), "\" SUCCESS");

#define TestAssertEquals(result, expected) \
test_ctx->m_testCount++;\
if(result != expected)\
{\
	test_ctx->Logger().Log(MakeLogLevel(Pulsar::TestLogLevel::UnitTestFailure), "			Unit Test \"", test_ctx->GetName(), "\" FAIL : ", #result, " has value \"", result, "\" but was expected to be \"", expected, "\""); \
	test_ctx->m_failureCount++;\
}\
else\
	test_ctx->Logger().Log(MakeLogLevel(Pulsar::TestLogLevel::UnitTestSuccess), "			Unit Test \"", test_ctx->GetName(), "\" SUCCESS");

namespace Pulsar
{
	enum class TestLogLevel : uint8_t
	{
		All =				0xFF,
		Suite =				0x01,
		Module =			0x02,
		UnitTest =			0x04,
		UnitTestFailure =	0x08,
		UnitTestSuccess =	0x10,
		Step =				0x20,
		Result =			0x40
	};

	template<typename TestLogLevel>
	uint8_t MakeLogLevel(TestLogLevel level)
	{
		return (uint8_t)level;
	}

	template<typename TestLogLevel, typename... TestLogLevels>
	uint8_t MakeLogLevel(TestLogLevel level, TestLogLevels... levels)
	{
		return MakeLogLevel(level) | MakeLogLevel(levels...);
	}

	class UnitTest;
	class TestModule;
	class TestSuite;

	using UnitTestFunc = void (*) (UnitTest* test);

	class UnitTest
	{
	public:
		UnitTest(const char* name, TestModule* module);
		void Run();
		Logger& Logger();
		const char* GetName() { return m_name; }
		UnitTestFunc m_func;
		int m_testCount;
		int m_failureCount;

	private:
		const char* m_name;
		TestModule* m_module;
	};

	class TestModule
	{
	public:
		TestModule(TestSuite* suite, const char* name);
		void Run();
		Logger& Logger();
		int m_testCount;
		int m_failureCount;

	protected:
		const char* m_name;
		TestSuite* m_suite;
		std::vector<UnitTest> m_tests;
	};

	class TestSuite
	{
	public:
		TestSuite(const char* name, TestLogLevel levels);
		void AddTestModule(TestModule& module);
		void Run();
		Logger& Logger();
		int m_testCount;
		int m_failureCount;

	private:
		const char* m_name;
		std::vector<TestModule*> m_modules;
		Pulsar::Logger m_logger;
	};
}
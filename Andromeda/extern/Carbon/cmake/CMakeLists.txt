cmake_minimum_required(VERSION 3.15.7)

# set the project name
project(Carbon)

# set directory path variable
set(CMVAR_DIR_PROJECTROOT ..)
set(CMVAR_DIR_CMAKE "${CMVAR_DIR_PROJECTROOT}/cmake")
set(CMVAR_DIR_SRC "${CMVAR_DIR_PROJECTROOT}/code/src")
set(CMVAR_DIR_INCLUDE "${CMVAR_DIR_PROJECTROOT}/code/include")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the list of sources files to build
set(CMVAR_SRCFILES
	"${CMVAR_DIR_SRC}/vector3.cpp"
	"${CMVAR_DIR_SRC}/matrix3x4.cpp"
	"${CMVAR_DIR_SRC}/quaternion.cpp"
	"${CMVAR_DIR_SRC}/transform.cpp"
	)

# define static lib as output
add_library(Carbon STATIC ${CMVAR_SRCFILES})

# set include directory
target_include_directories(Carbon PUBLIC ${CMVAR_DIR_INCLUDE})


######################################
############## UnitTest ##############
######################################

project(CarbonTest)
enable_testing()

set(CMVAR_DIR_TEST "${CMVAR_DIR_PROJECTROOT}/test")
set(CMVAR_DIR_TESTSRC "${CMVAR_DIR_TEST}/src")
set(CMVAR_DIR_TESTINCLUDE "${CMVAR_DIR_TEST}/include")

set(CMVAR_TESTSRCFILES
	"${CMVAR_DIR_TESTSRC}/main_test.cpp"
	)

# create test executable
add_executable(CarbonTest ${CMVAR_TESTSRCFILES})

# dependencies
target_link_libraries(CarbonTest Carbon)
target_link_libraries(CarbonTest Pulsar)

# set include directory
target_include_directories(CarbonTest PUBLIC ${CMVAR_DIR_TESTINCLUDE})

add_test(NAME CarbonTest COMMAND CarbonTest)

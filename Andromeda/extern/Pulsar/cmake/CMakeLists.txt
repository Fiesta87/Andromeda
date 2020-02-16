cmake_minimum_required(VERSION 3.15.7)

# set the project name
project(Pulsar)

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
	"${CMVAR_DIR_SRC}/pulsar.cpp"
	)

# define static lib as output
add_library(Pulsar STATIC ${CMVAR_SRCFILES})

# set include directory
target_include_directories(Pulsar PUBLIC ${CMVAR_DIR_INCLUDE})

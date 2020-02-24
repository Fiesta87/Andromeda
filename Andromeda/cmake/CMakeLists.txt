cmake_minimum_required(VERSION 3.15.7)

# set the project name
project(Andromeda)

# set directory path variable
set(CMVAR_DIR_PROJECTROOT ..)
set(CMVAR_DIR_CMAKE "${CMVAR_DIR_PROJECTROOT}/cmake")
set(CMVAR_DIR_SRC "${CMVAR_DIR_PROJECTROOT}/code/src")
set(CMVAR_DIR_INCLUDE "${CMVAR_DIR_PROJECTROOT}/code/include")
set(CMVAR_DIR_EXTERN "${CMVAR_DIR_PROJECTROOT}/extern")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the list of sources files to build
set(CMVAR_SRCFILES
	"${CMVAR_DIR_SRC}/andromeda/config.cpp"
	"${CMVAR_DIR_SRC}/andromeda/engine.cpp"
	"${CMVAR_DIR_SRC}/andromeda/world.cpp"
	)

# add extern references
add_subdirectory("${CMVAR_DIR_EXTERN}/Pulsar/cmake" "${CMVAR_DIR_EXTERN}/Pulsar/cmake/out")
add_subdirectory("${CMVAR_DIR_EXTERN}/Photon/cmake" "${CMVAR_DIR_EXTERN}/Photon/cmake/out")
add_subdirectory("${CMVAR_DIR_EXTERN}/Carbon/cmake" "${CMVAR_DIR_EXTERN}/Carbon/cmake/out")

# define static lib as output
add_library(Andromeda STATIC ${CMVAR_SRCFILES})

# set include directory
target_include_directories(Andromeda PUBLIC ${CMVAR_DIR_INCLUDE})

# dependencies
target_link_libraries(Andromeda Pulsar)
target_link_libraries(Andromeda Photon)
target_link_libraries(Andromeda Carbon)
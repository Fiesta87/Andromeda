cmake_minimum_required(VERSION 3.15.7)

# set the project name
project(GameDemo)

# set directory path variable
set(CMVAR_DIR_PROJECTROOT ..)
set(CMVAR_DIR_CMAKE "${CMVAR_DIR_PROJECTROOT}/cmake")
set(CMVAR_DIR_SRC "${CMVAR_DIR_PROJECTROOT}/code/src")
set(CMVAR_DIR_INCLUDE "${CMVAR_DIR_PROJECTROOT}/code/include")
set(CMVAR_DIR_ANDROMEDA "${CMVAR_DIR_PROJECTROOT}/../Andromeda")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the list of sources files to build
set(CMVAR_SRCFILES
	"${CMVAR_DIR_SRC}/main.cpp"
	)

# add andromeda references
add_subdirectory("${CMVAR_DIR_ANDROMEDA}/cmake" "${CMVAR_DIR_ANDROMEDA}/cmake/out")

# define static lib as output
add_executable(GameDemo ${CMVAR_SRCFILES})

# set include directory
target_include_directories(GameDemo PUBLIC ${CMVAR_DIR_INCLUDE})

# dependencies
target_link_libraries(GameDemo Andromeda)

# enable Smart Command Line Arguments extension for Visual Studio.
# FIX_ME CMake need to generate sln and vcxproj to enable Smart Command Line Arguments extension.
# set_property(TARGET GameDemo PROPERTY VS_GLOBAL_SmartCmdArgJsonFile "${CMVAR_DIR_PROJECTROOT}/project.args.json")
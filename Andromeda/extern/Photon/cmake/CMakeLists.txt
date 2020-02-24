cmake_minimum_required(VERSION 3.15.7)

# set the project name
project(Photon)

# set directory path variable
set(CMVAR_DIR_PROJECTROOT ..)
set(CMVAR_DIR_CMAKE "${CMVAR_DIR_PROJECTROOT}/cmake")
set(CMVAR_DIR_SRC "${CMVAR_DIR_PROJECTROOT}/code/src")
set(CMVAR_DIR_INCLUDE "${CMVAR_DIR_PROJECTROOT}/code/include")
set(CMVAR_DIR_LIBS "${CMVAR_DIR_PROJECTROOT}/libs")
set(CMVAR_VULKAN_LIB "${CMVAR_DIR_PROJECTROOT}/libs/Vulkan/lib/vulkan-1.lib")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# set the list of sources files to build
set(CMVAR_SRCFILES
	"${CMVAR_DIR_SRC}/photon/window.cpp"
	)

# add GLFW reference
add_subdirectory("${CMVAR_DIR_LIBS}/glfw-3.3.2" "${CMVAR_DIR_CMAKE}/out")

# define static lib as output
add_library(Photon STATIC ${CMVAR_SRCFILES})

# set include directory
#option(GLFW_VULKAN_STATIC "Assume the Vulkan loader is linked with the application" ON)
set(GLFW_VULKAN_STATIC 1)
target_include_directories(Photon PUBLIC ${CMVAR_DIR_INCLUDE})
target_include_directories(Photon PUBLIC "${CMVAR_DIR_LIBS}/Vulkan/include")

# dependencies
#link_directories(${CMVAR_DIR_LIBS})
#target_link_directories(Photon PRIVATE "E:/Programmation/Projets/C++/Andromeda/Andromeda/extern/Photon/libs")
target_link_libraries(Photon glfw)
#target_link_libraries(Photon "Vulkan/lib/vulkan-1.lib")
#target_link_libraries(${PROJECT_NAME} LINK_PRIVATE ${CMVAR_VULKAN_LIB})
#target_link_libraries(${PROJECT_NAME} "${CMVAR_DIR_LIBS}/Vulkan/lib/vulkan-1.lib")
target_link_libraries(Photon "E:/Programmation/Projets/C++/Andromeda/Andromeda/extern/Photon/libs/Vulkan/lib/vulkan-1.lib")
target_link_libraries(Photon Pulsar)
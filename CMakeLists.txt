cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project( vulkanEngine VERSION 2.0.0 )
set( vulkanEngine_VERSION_ABI 3)

# Disable in source building
if( "${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}" )
  message( FATAL "no in source building allowed." )
endif()

list(APPEND CMAKE_MODULE_PATH
  ${PROJECT_SOURCE_DIR}/CMake
  ${CMAKE_SOURCE_DIR}/CMake/common)

# Default build type is Debug
if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug )
endif( NOT CMAKE_BUILD_TYPE )

if ( CMAKE_BUILD_TYPE MATCHES "Debug" )
  add_definitions( -DDEBUG )
endif( )

include(GitExternal)

set( COMMON_PROJECT_DOMAIN randomUser )
set( VULKANENGINE_DESCRIPTION "VulkanEngine" )
include(Common)

# Allow warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error")

option( VULKANENGINE_WITH_EXAMPLES "VulkanEngine examples" ON )

set(STBI_INCLUDE_DIR ../stbi)
common_find_package( Vulkan REQUIRED SYSTEM )
common_find_package( GLM SYSTEM )
common_find_package( GLFW3 SYSTEM )

list( APPEND LAVA_DEPENDENT_LIBRARIES Vulkan STBI )

IF (NOT WIN32)
  link_libraries( -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread )
endif()

common_find_package_post( )

add_subdirectory( vulkanEngine )
add_subdirectory( demos )

configure_file(
  CMake/glsl2spv.cmake
  ${PROJECT_BINARY_DIR}/${CMAKE_MODULE_INSTALL_PATH}/glsl2spv.cmake
  COPYONLY
  )
install( FILES CMake/glsl2spv.cmake
  DESTINATION ${CMAKE_MODULE_INSTALL_PATH} COMPONENT dev )

set(DOXYGEN_MAINPAGE_MD ${PROJECT_SOURCE_DIR}/README.md)
set(DOXYGEN_EXTRA_INPUT ${DOXYGEN_MAINPAGE_MD})
include(CPackConfig)
include(DoxygenRule)
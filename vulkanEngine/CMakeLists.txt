source_group(\\ FILES CMakeLists.txt)

set( VULKANENGINE_PUBLIC_HEADERS
    Foo.h
)

set( VULKANENGINE_SOURCES
    Foo.cpp
)

set( VULKANENGINE_HEADERS
)
set( VULKANENGINE_LINK_LIBRARIES
	${VULKAN_LIBRARY}
	${STBI_LIBRARIES}
)

common_library( vulkanEngine )
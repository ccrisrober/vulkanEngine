#ifndef __VULKANENGINE_INCLUDES__
#define __VULKANENGINE_INCLUDES__

/*#if defined ( __ANDROID__ )
  #define VULKANENGINE_PLATFORM_ANDROID
#elif defined( __APPLE__ )
  #include <TargetConditionals.h>
  #if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
    #define VULKANENGINE_PLATFORM_IOS
  #else
    #define VULKANENGINE_PLATFORM_OSX
  #endif
#elif defined( __MINGW32__ ) || defined( WIN32 ) || defined( __WIN32__ )
  #define VULKANENGINE_PLATFORM_WINDOWS
#else
  #define VULKANENGINE_PLATFORM_LINUX
#endif

#if defined( VULKANENGINE_PLATFORM_WINDOWS ) || defined( VULKANENGINE_PLATFORM_LINUX ) ||defined( VULKANENGINE_PLATFORM_OSX )
  #define VULKANENGINE_PLATFORM_DESKTOP
#endif

#if defined( VULKANENGINE_PLATFORM_IOS ) || defined( VULKANENGINE_PLATFORM_ANDROID )
  #define VULKANENGINE_PLATFORM_MOBILE
#endif*/

//#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>

#if defined( __MINGW32__ ) || defined( WIN32 ) || defined( __WIN32__ )
  #define VULKANENGINE_PLATFORM_WINDOWS
  #define VULKANENGINE_KHR_EXT "VK_KHR_win32_surface"
/*#elif defined(VK_KHR_android_surface)
  #define VULKANENGINE_PLATFORM_ANDROID
  #define VULKANENGINE_KHR_EXT "VK_KHR_android_surface"
#elif defined(VK_KHR_display)
  #define VULKANENGINE_KKHR_EXT "VK_KHR_display"
#elif defined(VK_KHR_wayland_surface)
  #define VULKANENGINE_KHR_EXT "VK_KHR_wayland_surface"*/
#elif defined(_GLFW_X11)
  #define VULKANENGINE_PLATFORM_LINUX
  #define VULKANENGINE_KHR_EXT "VK_KHR_xcb_surface"
#else //elif defined(VK_KHR_xlib_surface)
  #define VULKANENGINE_PLATFORM_LINUX
  #define VULKANENGINE_KHR_EXT "VK_KHR_xcb_surface"
/*#elif defined(VK_MVK_ios_surface)
  #define VULKANENGINE_KHR_ExT "VK_MVK_ios_surface"
#elif defined(VK_MVK_macos_surface)
  #define VULKANENGINE_KHR_ExT "VK_MVK_macos_surface"*/
#endif

#include <vulkan/vulkan.hpp>

#include <iostream>

#define VULKANENGINE_RUNTIME_ERROR(s) throw std::runtime_error( s );

#endif /* __VULKANENGINE_INCLUDES__ */

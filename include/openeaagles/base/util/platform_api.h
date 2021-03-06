
#ifndef __oe_base_util_platform_api_H__
#define __oe_base_util_platform_api_H__

//------------------------------------------------------------------------------
// Operating system, compiler and window manager specific includes
//------------------------------------------------------------------------------

#if defined(WIN32)
  #if defined(__MINGW32__)
    // MinGW
    #include "openeaagles/base/util/platform/platform_api_mingw.h"
  #else
    // Visual Studio
    #include "openeaagles/base/util/platform/platform_api_msvc.h"
  #endif
#else
  // Linux GCC
  #include "openeaagles/base/util/platform/platform_api_linux.h"
#endif

#endif


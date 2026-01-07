// thí file is to define something, please do not include this file
#pragma once
#include <string>
#if defined(_WIN32)
    #define OS_WINDOWS
#elif defined(__linux__)
    #define OS_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
    #define OS_MACOS
#elif defined(__unix__)
    #define OS_UNIX
#elif defined(__android__)
    #define OS_ANDROID
#endif

inline const char *get_os_name() {
#ifdef OS_WINDOWS
    return "Windows";
#elif defined(OS_LINUX)
    return "Linux";
#elif defined(OS_MACOS)
    return "macOS";
#elif defined(OS_UNIX)
    return "Unix";
#elif defined(OS_ANDROID)
    return "Android";
#else   
    return "Unknown";
#endif
}

<<<<<<< HEAD
#define CNUS_VERSION "0.0.1beta"
=======
#define CNUS_VERSION "0.0.1vBETA"
>>>>>>> 4b119560c1d7cb997167b9dec0492c61775f4358

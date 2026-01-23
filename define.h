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

#define CNUS_VERSION "0.0.5vBETA"

#define auto_display void display() {glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);glutSwapBuffers();}\

#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
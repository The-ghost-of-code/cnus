// this file is to define something, please do not include this file
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

#define C_BLUE "\033[34m"
#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_WHITE "\033[37m"
#define C_BLACK "\033[30m"
#define C_UNDER_BLACK "\033[4;30m"
#define C_UNDER_WHITE "\033[4;37m"
#define C_BACKGROUND_BLACK "\033[40m"
#define C_BACKGROUND_RED "\033[41m"
#define C_BACKGROUND_GREEN "\033[42m"
#define C_UNDER_RED "\033[4;31"
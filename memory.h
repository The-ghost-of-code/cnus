// beta, may contain bugs
#pragma once
#include "printk.h"
#include <windows.h>
template<typename T>
bool is_ptr_null(const T* ptr) {
    if (ptr == nullptr) {
        return true;
    }
    return false;
}

template<typename T>
void make_null_ptr(T*& ptr) {
    delete ptr;
    ptr = nullptr;
}

// check for free ram left (high or low)
void check_free_ram() {
    #if defined(_WIN32) || defined(_WIN64)
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);
        DWORDLONG freeRam = memInfo.ullAvailPhys / (1024 * 1024); // in MB
        if (freeRam < 1024) {
            printk("Warning: Low RAM available: ");
            printk(freeRam, " MB");
        } else {
            printk("RAM available: ");
            printk(freeRam, " MB");
        }
    #elif defined(__linux__)
        struct sysinfo memInfo;
        sysinfo(&memInfo);
        long long freeRam = memInfo.freeram / (1024 * 1024); // in MB
        if (freeRam < 1024) {
            printk("Warning: Low RAM available: ");
            printk(freeRam, " MB");
        } else {
            printk("RAM available: ");
            printk(freeRam, " MB");
        }
    #else
        #error "Unsupported platform for RAM check"
    #endif
}
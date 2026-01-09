#pragma once
#include <iostream>
#include <cstring>
#include <type_traits>
#include "error.h"

ErrorCode ec;
template <typename T>
void printk(T text1) {
    std::cout << text1 << std::endl;
}
// printk has a problem that it cannot print intergers and strings at the same time (fixed)
template <typename Autodefine1, typename Autodefine2>
void printk(const Autodefine1& text1,const  Autodefine2& text2, const char* h = nullptr) {
    // we remove * in the template to avoid pointer types
    if(h && std::strcmp(h, ":") == 0) {
        std::cout << text1 << ": " << text2 << std::endl;
    }
    if (h && std::strcmp(h, ",") == 0) {
        std::cout << text1 << ", " << text2 << std::endl;
    }
    if (h && std::strcmp(h, ".") == 0) {
        std::cout << text1 << ". " << text2 << std::endl;
    }
    if (h && std::strcmp(h, ";") == 0) {
        std::cout << text1 << "; " << text2 << std::endl;
    }
    if (h == nullptr) {
        std::cout << text1 << text2 << std::endl;
    }
}
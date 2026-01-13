#pragma once
#include <iostream>
#include <cstring>
#include <type_traits>
#include "error.h"

ErrorCode ec;
template <typename T>
void printk(T text1) {
    std::cout << text1;
}
// printk has a problem that it cannot print intergers and strings at the same time (fixed)
template <typename Autodefine1, typename Autodefine2>
void printk(const Autodefine1& text1,const  Autodefine2& text2, const char* h = "", const char * end = " ") {
    // we remove * in the template to avoid pointer types
    if(h && std::strcmp(h, ":") == 0) {
        std::cout << text1 << ": " << text2;
    }
    if (h && std::strcmp(h, ",") == 0) {
        std::cout << text1 << ", " << text2;
    }
    if (h && std::strcmp(h, ".") == 0) {
        std::cout << text1 << ". " << text2;
    }
    if (h && std::strcmp(h, ";") == 0) {
        std::cout << text1 << "; " << text2;
    }
    if (h && std::strcmp(h, "") == 0) {
        std::cout << text1 << text2 ;
    }
    if (end && std::strcmp(end, "endl") == 0) {
        std::cout << std::endl;
    }
    if (end && std::strcmp(end, " ") == 0) {
        std::cout << " ";
    }
}
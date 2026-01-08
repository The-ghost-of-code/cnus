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

template <typename Autodefine1, typename Autodefine2>
void printk(Autodefine1 text1,const  Autodefine2* text2, const char* h = nullptr) {
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
}
#pragma once
#include <iostream>
#include <type_traits>
#include "error.h"

ErrorCode ec;
template <typename T>
void printk(T text1) {
    std::cout << text1 << std::endl;
}

template <typename Autodefine1, typename Autodefine2>
void printk(Autodefine1 text1,const  Autodefine2* text2 = nullptr, const char* h = nullptr) {
    if (h == " ") {
        std::cout << text1 << " " << text2 << std::endl;
    }
    if (h == ",") {
        std::cout << text1 << ", " << text2 << std::endl;
    }
    if (h == ".") {
        std::cout << text1 << ". " << text2 << std::endl;
    }
    if (h == ";") {
        std::cout << text1 << "; " << text2 << std::endl;
    }
    if (h == nullptr) {
        std::cout << text1 << text2 << std::endl;
    }
    if constexpr (std::is_arithmetic<Autodefine1>::value && std::is_arithmetic<Autodefine2>::value) {
        if (h == "+") {
            std::cout << (text1 + text2) << std::endl;
        }
        if (h == "-") {
            std::cout << (text1 - text2) << std::endl;
        }
        if (h == "*") {
            std::cout << (text1 * text2) << std::endl;
        }
        if (h == "/") {
            if (text2 != 0) {
                std::cout << (text1 / text2) << std::endl;
            } else {
                std::cout << to_string(ErrorCode::DIVZERO) << std::endl;
            }
        }
    }
}


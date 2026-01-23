#pragma once
#include <iostream>

void printk() {}

template<typename T, typename... Args>

void printk(T first, Args... args) {
    std::cout << first;
    printk(args...);
} // update and make file simpler to read and free little storage in compiling

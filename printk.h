#pragma once
#include <iostream>

void printk() {}

template<typename T, typename... Args>

void printk(T first, Args... args) {
    std::cout << first;
    printk(args...);
}
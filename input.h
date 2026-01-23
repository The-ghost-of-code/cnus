#pragma once
#include <iostream>

void input() {};

template<typename T, typename... other>

void input(T t, other... others) {
    std::cin >> t;
    input(others...);
}
// beta, may contain bugs
#pragma once
#include "printk.h"
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
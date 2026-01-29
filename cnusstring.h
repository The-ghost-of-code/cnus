#include <sstream>
#include <iostream>
#include <string>

bool is_real_number(const std::string& x) {
    std::stringstream ss(x);
    double a;
    char c;
    if (!(ss >> a)) return false;
    if (ss >> c) return false;
    else return true;
}

bool is_complex_num(std::string a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'i') {
            return true;
            break;
        }
    }
    return false;
}
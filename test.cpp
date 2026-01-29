#include "cnus.h"

int main() {
    complex f;
    input(f);
    auto y = to_complex(f);
    printk(y);
}
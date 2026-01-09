#include "printk.h"

namespace math_basic {
    constexpr double PI = 3.141592653589793;
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
    double divide(double a, double b) {
        if (b == 0) {
            printk(ErrorCode::DIVZERO);
            return 0;
        }
        return a / b;
    }
    double reg_to_rad(double degree) {
        return degree * (PI / 180.0);
    }
    double sin(double x) {
        double term = x;
        double sum = x;
        for (int n = 1; n <= 10; n++) {
            term *= -x * x / ((2*n) * (2*n + 1));
            sum += term;
        }
        return sum;
    }
    double cosin(double angel) {
        double term = 1.0;
        double sum = 1.0;
        for (int i = 1; i <= 10; i++) {
            term *= -angel * angel / ((2 * i - 1) * (2 * i));
            sum += term;
        }
        return sum;
    }
    double exp(double x) {
        double term = 1.0;  // x^0 / 0!
        double sum  = 1.0;

        for (int n = 1; n <= 100; ++n) {
            term *= x / n;
            sum  += term;
        }
        return sum;
    
    }
    // ln(A)
    double ln(double a) {
        if (a <= 0) return 0.0;
        const double E = 2.718281828459045;
        int k = 0;
        while (a > 2)  { a /= E; ++k; }
        while (a < 0.5){ a *= E; --k; }
        double y = (a - 1) / (a + 1);
        double y2 = y * y, term = y, sum = y;
        for (int n = 1; n <= 15; ++n) {
            term *= y2;
            sum += term / (2*n + 1);
        }
        return 2 * sum + k;
    }
};

// derivative calculator is written by hand, so the database is need to be expanded manually
void derivative(std::string func) {
    if (func == "x^n") {
        printk("n*x^(n-1)");
    }
    else if (func == "sin(x)") {
        printk("cos(x)");
    }
    else if (func == "cos(x)") {
        printk("-sin(x)");
    }
    else if (func == "e^x") {
        printk("e^x");
    }
    else if (func == "ln(x)") {
        printk("1/x");
    }
    else if(func == "constant") {
        printk("0");
    }
    else if (func == "1/x") {
        printk("-1/x^2");
    }
    // add more functions as needed, add here
    else {
        printk("Derivative not found in database.");
    }
}

double integral(std::string func, double a, double b) {
    if (func == "x^n") {
        // integral of x^n is (x^(n+1))/(n+1)
        // for simplicity, we assume n=1 here
        double result = (b * b * b) / 3 - (a * a * a) / 3;
        return result;
    }
    if (func == "sin(x)") {
        // integral of sin(x) is -cos(x)
        double result = -math_basic::cosin(math_basic::reg_to_rad(b)) + math_basic::cosin(math_basic::reg_to_rad(a));
        return result;
    }
    if (func == "cos(x)") {
        // integral of cos(x) is sin(x)
        double result = math_basic::sin(math_basic::reg_to_rad(b)) - math_basic::sin(math_basic::reg_to_rad(a));
        return result;
    }
    if (func == "e^x") {
        // integral of e^x is e^x
        double result = math_basic::exp(b) - math_basic::exp(a);
        return result;
    }
    if (func == "1/x") {
        // integral of 1/x is ln|x|
        double result = math_basic::ln(b) - math_basic::ln(a);
        return result;
    }
    
    else {
        printk("Integral not found in database.");
        return 0;
    }
}
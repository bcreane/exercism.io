#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>
#include <cmath>

namespace triangle {
    enum Triangle_t {
        equilateral, isosceles, scalene
    };

    Triangle_t kind(float a, float b, float c) {
        if (a <= 0 || b <= 0 || c <= 0 || a+b<c || b+c<a || a+c<b) {
            throw std::domain_error("bad triangle");
        } else if (a == b && b == c) {
            return equilateral;
        } else if (a==b || b==c || a==c) {
            return isosceles;
        } else {
            return scalene;
        }
    }
}

#endif

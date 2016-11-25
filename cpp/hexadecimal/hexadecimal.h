#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include <string>
#include <cstdint>

namespace hexadecimal {
    uint64_t convert(const std::string& h) {
        uint64_t i = 0, power = 1;

        for (ssize_t ndx = h.length()-1; ndx >= 0; --ndx, power *= 0x10) {
            int digit;

            if (h[ndx] >= 'a' && h[ndx] <= 'f') {
                digit = h[ndx] -'a' + 10;
            } else if (h[ndx] >= '0' && h[ndx] <= '9') {
                digit = h[ndx] -'0';
            } else {
                return 0;
            }

            i += digit * power;
        }

        return i;
    }
}

#endif


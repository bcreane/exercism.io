#if !defined(BINARY_H)
#define BINARY_H

#include <string>
using namespace std;

namespace binary {
    int convert(const string& b) {
        int place_value(1);
        int value(0);

        for (reverse_iterator<string::const_iterator> rit = b.rbegin(); rit != b.rend(); ++rit) {
            const int digit = *rit - '0';

            if (digit != 0 && digit != 1)
                return 0;

            value += digit * place_value;
            place_value *= 2;
        }

        return value;
    }
}

#endif

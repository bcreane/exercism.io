#if !defined(TRINARY_H)
#define TRINARY_H

#include <string>
using namespace std;

namespace trinary {
    int to_decimal(const string& tri) {
        int place_value(1);
        int value(0);
        
        for (reverse_iterator<string::const_iterator> rit = tri.rbegin(); rit != tri.rend(); ++rit) {
            const int digit = *rit - '0';
            
            if (digit < 0 || digit > 2)
                return 0;

            value += digit * place_value;
            place_value *= 3;
        }

        return value;
    }
}

#endif

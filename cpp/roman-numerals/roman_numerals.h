#if !defined(ROMAN_NUMERALS_H)
#define ROMAN_NUMERALS_H

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

namespace {
    string place_value(int d, size_t ndx) {

        vector<vector<string>> numerals = {
            {"I", "V", "X"},
            {"X", "L", "C"},
            {"C", "D", "M"},
            {"M", "",  ""},
        };

        if (ndx > 3) ndx = 3;
        const string& one = numerals[ndx][0];
        const string& five = numerals[ndx][1];
        const string& ten = numerals[ndx][2];

        switch (d) {
            case 1: return one;
            case 2: return one + one;
            case 3: return one + one + one;
            case 4: return one + five;
            case 5: return five;
            case 6: return five + one;
            case 7: return five + one + one;
            case 8: return five + one + one + one;
            case 9: return one + ten;
        }

        return "";
    }
}

namespace roman {
    string convert(int i) {
        if (i > 3999) {
            throw std::domain_error("can't handle bigger than 3999!");
        }

        string r;
        size_t ndx(0);
        while (i > 0) {
            int d = i % 10;
            r.insert(0, place_value(d, ndx));
            i /= 10;
            ndx++;
        }

        return r;
    }
}

#endif

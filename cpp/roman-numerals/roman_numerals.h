#if !defined(ROMAN_NUMERALS_H)
#define ROMAN_NUMERALS_H

#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

namespace {
    string place_value(int d, size_t pv) {

        assert(d <= 9999 && pv <= 3);

        vector<vector<string>> numerals = {
            {"I", "V", "X"},
            {"X", "L", "C"},
            {"C", "D", "M"},
            {"M", "",  ""},
        };

        const string& one = numerals[pv][0];
        const string& five = numerals[pv][1];
        const string& ten = numerals[pv][2];

        if (pv == 3) {  // thousands ...
            string s;
            for (size_t ndx = 0; ndx < d; ++ndx)
                s += one;

            return s;

        } else {        // ones, tens, hundreds ...
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
        }

        return "";
    }
}

namespace roman {
    string convert(int i) {
        if (i > 9999) {
            throw std::domain_error("can't handle bigger than 9999!");
        }

        string r;
        size_t pv(0);
        while (i > 0) {
            int d = i % 10;
            r.insert(0, place_value(d, pv));
            i /= 10;
            pv++;
        }

        return r;
    }
}

#endif

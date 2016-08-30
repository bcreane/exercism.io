#if !defined(SAY_H)
#define SAY_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

namespace {
    unordered_map<uint64_t, string> num_name = {
        {0, "zero"},     {1, "one"},        {2, "two"},       {3, "three"},
        {4, "four"},     {5, "five"},       {6, "six"},       {7, "seven"},
        {8, "eight"},    {9, "nine"},       {10, "ten"},      {11, "eleven"},
        {12, "twelve"},  {13, "thirteen"},  {14, "fourteen"}, {15, "fifteen"},
        {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
        {20, "twenty"},  {30, "thirty"},    {40, "forty"},    {50, "fifty"},
        {60, "sixty"},   {70, "seventy"},   {80, "eighty"},   {90, "ninety"},
    };

    unordered_map<size_t, string> place_value_name = {
        {0, ""}, {1, "thousand"}, {2, "million"}, {3, "billion"}, {4, "trillion"}
    };

    /**
     * break i into digits in a vector
     */
    vector<int> to_vec(uint64_t i) {
        vector<int> v;
        while (i > 0) {
            v.push_back(i % 10);
            i /= 10;
        }

        reverse(v.begin(), v.end());

        return v;
    }

    /**
     * Convert 0...999 to english string equivalent
     */
    const string hundreds_to_str(const vector<int>& num) {
        vector<int> v(num);
        string s;

        if (v.size() > 3)
            throw std::domain_error("valid: 0 .. 999");

        if (v.size() == 3) {
            if (v[0] != 0)
                s = num_name[v[0]] + " hundred ";
            v.erase(v.begin(), v.begin()+1);
        }

        switch (v.size()) {
            case 0:
                s += s.length() > 0 ? s : "zero";
                break;
            case 1:
                s += num_name[v[0]];
                break;
            case 2: {
                if (v[0] != 0 || v[1] != 0) {
                    int val = v[0]*10 + v[1];
                    if (val < 20 || val % 10 == 0)  // teens or multiple of 10
                        s += num_name[val];
                    else                            // all others, <= 99
                        s += num_name[v[0]*10] + string("-") + num_name[v[1]];
                }
                break;
            }
            default: return "error";
        }

        if (s[s.length()-1] == ' ')                 // erase trailing space
            s.erase(s.end() - 1, s.end());

        return s;
    }
}

namespace say {

    /**
     * Return the written form of the number i, e.g. 1,000 -> "one thousand".
     */
    const string in_english(uint64_t i) {
        if (static_cast<int64_t>(i) < 0 || i >= 1000ULL*1000ULL*1000ULL*1000ULL)
            throw std::domain_error("valid: 0 ... 999,999,999,999,999");

        // break digits into place value groups of 3 (or less) digits
        auto v(to_vec(i));
        vector<vector<int>> pv;
        while (v.size() > 0) {
            const size_t len = min(static_cast<size_t>(3), v.size());
            pv.emplace_back(v.end()-len, v.end());
            v.erase(v.end()-len, v.end());
        }

        reverse(pv.begin(), pv.end());

        // handle 0 case
        if (pv.size() == 0) {
            pv.push_back(vector<int>(0));
        }

        // build up string by processing place values, one by one
        string num;
        for (size_t dec = 0; dec < pv.size(); ++dec) {
            auto r = hundreds_to_str(pv[dec]);
            if (r.length() > 0) {
                const size_t i = pv.size() - dec - 1;
                r += " " + place_value_name[i];
            }
            num += (num.length() > 0 && num[num.length()-1] != ' ' ? " " : "") + r;
        }

        if (num[num.length()-1] == ' ')                 // erase trailing space
            num.erase(num.end() - 1, num.end());

        return num;
    }
}

#endif

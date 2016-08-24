#include <unordered_map>
#include <cctype>
#include <iostream>
#include <strings.h>

#include "anagram.h"

bool anagram::is_anagram(const std::string& a, const std::string& b)
{
    if (strcasecmp(a.c_str(), b.c_str()) == 0)
        return false;

    std::unordered_map<char, size_t> a_cnt, b_cnt;

    for (auto c : a)
        a_cnt[std::tolower(c)]++;

    for (auto c : b)
        b_cnt[std::tolower(c)]++;

    return a_cnt == b_cnt;
}

std::vector<std::string>
anagram::matches(const std::vector<std::string>& list)
{
    std::vector<std::string> matches;
    for (const std::string& s : list) {
        if (is_anagram(word_, s)) {
            matches.push_back(s);
        }
    }

    return matches;
}

#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <vector>
#include <string>

struct anagram {
    anagram(const std::string& word) : word_(word) {}
    std::vector<std::string> matches(const std::vector<std::string>&);

private:
    const std::string word_;
    bool is_anagram(const std::string& a, const std::string& b);
};

#endif


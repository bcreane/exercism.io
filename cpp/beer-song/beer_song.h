#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <string>
#include <algorithm>

namespace {
    const std::string str_to_lower(const std::string& in) {
        std::string s(in);
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    const std::string get_number_bottles(int n) {
        return n == 0 ? "No more" : std::to_string(n);
    }

    const std::string get_bottles(int n) {
        return std::string("bottle") + (n == 1 ? "" : "s");
    }

    const std::string get_bottle_phrase(int n) {
        return get_number_bottles(n) + " " + get_bottles(n);
    }

    const std::string get_take_phrase(int n) {
        switch(n) {
        case 0:  return "Go to the store and buy some more, ";
        case 1:  return "Take it down and pass it around, ";
        default: return "Take one down and pass it around, ";
        }
    }
}

namespace beer {
    // Sing a single verse
    const std::string verse(ssize_t n) {
        return get_bottle_phrase(n) + " of beer on the wall, " +
               str_to_lower(get_bottle_phrase(n)) + " of beer.\n" +

               get_take_phrase(n) +
               str_to_lower(get_bottle_phrase((n > 0) ? n-1 : 99)) +
               " of beer on the wall.\n";
    }

    // Sing a range of verses
    const std::string sing(ssize_t beg, ssize_t end) {
        std::string s;
        for (ssize_t n = beg; n >= end; --n) {
            s += verse(n) + (n > end ? "\n" : "");
        }
        return s;
    }

    // Sing a range of verses starting at beg and ending at 0
    const std::string sing(ssize_t beg) {
        return sing(beg, 0);
    }
}

#endif


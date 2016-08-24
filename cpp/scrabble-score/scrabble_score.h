#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H

#include <string>
#include <map>
#include <cctype>

using namespace std;

namespace {
    int get_letter_points(char c) {
        static map<char, int> points = {
            {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1},
            {'L', 1}, {'N', 1}, {'R', 1}, {'S', 1}, {'T', 1},
            {'D', 2}, {'G', 2},
            {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
            {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
            {'K', 5},
            {'J', 8}, {'X', 8},
            {'Q', 10}, {'Z', 10},
        };

        return points[toupper(c)];
    }
}

namespace scrabble_score {
    int score(const string& s) {
        int sum(0);
        for (auto c : s)
            sum += get_letter_points(c);

        return sum;
    }
}

#endif

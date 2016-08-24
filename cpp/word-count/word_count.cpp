#include "word_count.h"

#include <boost/tokenizer.hpp>
#include <string>

namespace {
    std::vector<std::string> tokenize(const std::string& text)
    {
        std::vector<std::string> words;
        
        std::string word;
        for (size_t ndx = 0; ndx < text.length(); ++ndx) {
            char c(std::tolower(text[ndx]));
            bool end_of_word(false);

            if (std::isupper(c) || std::islower(c) || std::isdigit(c)) {
                word.push_back(c);
            } else if (c == ' ' || c == '\n' || c == ',') {
                end_of_word = true;
            } else if (c == '\'') {
                if (ndx == 0 || ndx == text.length()-1) {   // ' at beginning or end of text
                    end_of_word = true;
                } else if (text[ndx-1] == ' ' || text[ndx+1] == ' ') {  // ' preceeded or followed by space
                    end_of_word = true;
                } else {
                    word.push_back(c);
                }
            }

            if (end_of_word || ndx == text.length()-1) {
                if (word.length() > 0)
                    words.push_back(word);
                word.clear();
            }
        }

        return words;
    }
}

const std::map<std::string, int>
word_count::words(const std::string& text)
{
    std::map<std::string, int> results;
    std::vector<std::string> tokens = tokenize(text);

    for (const auto& t : tokens) {
        results[t]++;
    }

    return results;
}


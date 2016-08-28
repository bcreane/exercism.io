#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

namespace crypto_square {
    struct cipher {
        cipher(const string& s) :
            s_(s),
            pt_(normalize()),
            rows_(0),
            cols_(0)
        {
            rows_ = static_cast<size_t>(sqrt(pt_.length()) + 0.5);

            cols_ = (pt_.length() > rows_ * rows_) ? rows_ + 1 : rows_;
        }

        const string normalize_plain_text() const {
            return pt_;
        }

        size_t size() const {return cols_;}

        const vector<string> plain_text_segments() const {
            vector<string> segs;
            segs.resize(rows_);

            for (size_t i = 0; i < pt_.length(); ++i) {
                size_t seg(i / cols_);
                segs[seg].push_back(pt_[i]);
            }

            return segs;
        }

        const string cipher_text() const {
            const vector<string> pts(plain_text_segments());
            string ct;

            for (size_t i = 0; i < pts[0].length(); ++i) {
                for (size_t seg = 0; seg < pts.size(); ++seg) {
                    if (i < pts[seg].length())
                        ct.push_back(pts[seg][i]);
                }
            }

            return ct;
        }

        const string normalized_cipher_text() const {
            string cipher(cipher_text()), nct;
            size_t i(0);

            for (size_t r = 0; r < rows_; r++) {
                for (size_t c = 0; c < cols_; c++) {
                    if (i < cipher.length())
                        nct += cipher[i++];
                }

                if (r < rows_ - 1)
                    nct += " ";
            }

            return nct;
        }

    private:
        const string s_, pt_;
        size_t rows_, cols_;

        const string normalize() const {
            string pt(s_);

            pt.erase(remove_if(pt.begin(), pt.end(),
                               [](char c) {
                                   return !isalpha(c) && !isdigit(c);
                               }),
                     pt.end());

            std::transform(pt.begin(), pt.end(), pt.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            return pt;
        }
    };
}

#endif

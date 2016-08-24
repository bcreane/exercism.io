#include "hamming.h"

size_t
hamming::compute(const std::string &a, const std::string &b)
{
    if (a.length() != b.length())
        throw std::domain_error("lengths must be the same");

    size_t distance(0);

    for (size_t ndx = 0; ndx < a.length(); ++ndx) {
        if (a[ndx] != b[ndx])
            ++distance;
    }

    return distance;
}

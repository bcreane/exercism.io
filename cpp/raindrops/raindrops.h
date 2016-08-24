#if !defined(RAINDROPS_H)
#define RAINDROPS_H

#include <string>
using namespace std;

namespace raindrops {
    const string convert(int i) {
        string p;
        if (i % 3 == 0)
            p += "Pling";
        if (i % 5 == 0)
            p += "Plang";
        if (i % 7 == 0)
            p += "Plong";
        if (p.length() == 0) {
            p = std::to_string(i);
        }

        return p;
    }
}

#endif


#if !defined(PRIME_FACTORS_H)
#define PRIME_FACTORS_H

#include <vector>

namespace prime_factors {
    const std::vector<int> of(int i) {
        std::vector<int> p;
        int div(2);

        while (i > 1) {
            if (i % div == 0) {
                p.push_back(div);
                i /= div;
            } else {
                div++;
            }
        }

        return p;
    }
}

#endif

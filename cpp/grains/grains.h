#if !defined(GRAINS_H)
#define GRAINS_H

#include <cstdint>

namespace grains {
    std::uint64_t square(std::uint64_t g) {
        std::uint64_t grains(1);
        return grains << (g-1);
    }

    std::uint64_t total() {
        return UINT64_MAX;
    }
}

#endif

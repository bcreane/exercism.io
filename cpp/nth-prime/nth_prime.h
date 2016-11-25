#ifndef NTH_PRIME_H
#define NTH_PRIME_H

#include <cstdint>
#include <vector>
#include <stdexcept>

namespace prime {
    uint64_t nth(uint64_t n) {
        if (n == 0)
            throw std::domain_error("invalid nth prime");

        std::vector<bool> primes(n*n, true);

        // Run the Sieve of Eratosthenes
        for (size_t i = 2; i < n; ++i) {
            for (size_t x = i*i; x < primes.size(); x += i) {
                primes[x] = false;
            }
        }

        // Find the nth prime
        uint64_t nth = 0, p = 2;
        for (size_t i = 2; i < primes.size(); ++i) {
            if (nth >= n)
                break;

            if (primes[i]) {
                p = i;
                nth++;
            }
        }

        return p;
    }
}

#endif


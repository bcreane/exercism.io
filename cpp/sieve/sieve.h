#if !defined(SIEVE_H)
#define SIEVE_H

#include <vector>
#include <string>
#include <unordered_set>

namespace sieve {
    std::vector<int> primes(const int upper) {
        std::unordered_set<int> is_not_prime;
        std::vector<int> primes;

        for (int i = 2; i <= upper/2; ++i) {
            int test = i, mult = 2;
            while (test <= upper) {
                test = i * mult++;
                is_not_prime.insert(test);
            }
        }

        for (int i = 2; i <= upper; ++i)
            if (is_not_prime.find(i) == is_not_prime.end())
                primes.push_back(i);

        return primes;
    }
}

#endif

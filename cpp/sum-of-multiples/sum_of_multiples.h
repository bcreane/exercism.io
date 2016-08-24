#if !defined(SUM_OF_MULTIPLES_H)
#define SUM_OF_MULTIPLES_H

#include <vector>
#include <set>
using namespace std;

namespace sum_of_multiples {
    int to(const vector<int>& set_of_ints, int upper) {
        set<int> multiples;
        int sum(0);
        
        for (auto i : set_of_ints) {
            int multiple(0);
            int mult(0);

            while ((multiple = ++mult * i) < upper) {
                if (multiples.find(multiple) == multiples.end())
                    sum += multiple;
                multiples.insert(multiple);
            }
        }
        
        return sum;
    }
}

#endif

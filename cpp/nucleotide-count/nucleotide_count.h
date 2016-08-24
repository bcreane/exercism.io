#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>

using namespace std;

namespace dna {
    struct counter {
        typedef map<char, int> DnaMap;

        // initialize count of nucelotides in "dna"
        counter(const string& dna) {
            for (auto d : string("ATCG")) {
                dna_counts_[d] = 0;
            }

            for (auto d : dna) {
                dna_counts_[d]++;
            }
        }

        // return map containing count of each of four nucleotides
        DnaMap nucleotide_counts() const {
            return dna_counts_;
        }

        // return count of specific nucleotide "d"
        int count(char d) const {
            DnaMap::const_iterator it = dna_counts_.find(d);
            if (it == dna_counts_.end()) {
                throw invalid_argument("bad nucleotide!");
            }
            
            return it->second;
        }

    private:
        DnaMap dna_counts_;
    };
}

#endif

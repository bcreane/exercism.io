#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

#include <string>
#include <unordered_map>

using namespace std;

namespace transcription {
    char to_rna(char d) {
        static unordered_map<char, char> dna_to_rna = {
            {'G', 'C'},
            {'C', 'G'},
            {'T', 'A'},
            {'A', 'U'}
        };

        return dna_to_rna[d];
    }

    const string to_rna(const string& dna_str) {
        string rna(dna_str);
        std::transform(rna.begin(), rna.end(), rna.begin(),
                       [](unsigned char d) {
                           return to_rna(d);
                       });
        return rna;
    }
}

#endif

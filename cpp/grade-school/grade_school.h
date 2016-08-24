#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

namespace grade_school {
    bool roster_sort(string a, string b) {
        return (a.front() < b.front());
    }

    struct school {
        map<int, vector<string>> roster() const {
            return roster_;
        }
        
        void add(string student, int grade) {
            roster_[grade].push_back(student);
            sort(roster_[grade].begin(), roster_[grade].end(), roster_sort);
        }

        vector<string> grade(int grade) {
            return roster_[grade];
        }
   
    private:
        map<int, vector<string>> roster_;
    };
}

#endif

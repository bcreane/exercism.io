#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <random>
#include <string>
#include <set>

using namespace std;

namespace robot_name {
    struct robot {
        robot () {
            set_unique_name();
        }

        string name() const {
            return name_;
        }

        void reset() {
            set_unique_name();
        }

    private:
        string name_;
        set<string> names_;

        // return random distribution, range: beg ... end
        int get_random(int beg, int end) const {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(beg, end);
            return dis(gen);
        }

        void set_unique_name() {
            do {
                name_ = get_name();
            } while (names_.find(name_) != names_.end());
            names_.insert(name_);
        }

        // return ^[:upper:]{2}d{3}, e.g. AB123
        string get_name() const {
            string name;
            name.push_back(get_random(0, 25)+'A');
            name.push_back(get_random(0, 25)+'A');
            name.push_back(get_random(0, 8)+'0');
            name.push_back(get_random(0, 8)+'0');
            name.push_back(get_random(0, 8)+'0');

            return name;
        }
    };
}
#endif

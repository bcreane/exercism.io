#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <string>
#include <sstream>

struct phone_number {
    phone_number(const std::string& ph) : ph_(ph) {
        ph_.erase(std::remove_if(ph_.begin(),
                                 ph_.end(),
                                 [](char x){return !std::isdigit(x);}),
                                 ph_.end());

        const size_t len = ph_.length();
        bool valid = true;

        if (len < 10 || len > 11) {
            valid = false;
        } else if (len == 11) {
            if (ph_[0] == '1') {
                ph_.erase(0, 1);
            } else {
                valid = false;
            }
        }

        if (!valid)
            ph_ = std::string(10, '0');
    }

    std::string number() const {
        return ph_;
    }

    std::string area_code() const {
        return std::string(ph_.begin(), ph_.begin()+3);
    }

    operator std::string() const {
        std::stringstream ss;
        ss << "(" << area_code() << ") "
           << std::string(ph_.begin()+3, ph_.begin()+6)
           << "-"
           << std::string(ph_.begin()+6, ph_.begin()+10);

        return ss.str();
    }

private:
    std::string ph_;
};

#endif

#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include <sstream>
#include <iomanip>

namespace {
    std::string int_to_padded_str(int i) {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << i;
        return ss.str();
    }
}

namespace date_independent {
    namespace clock {
        struct time {
            time(int hour, int minute) : 
                hours_(hour), minutes_(minute) { }

            std::string plus(int min) {
                minutes_ += min;
                if (minutes_ < 0) {
                    int h = (-minutes_ + 60) / 60;
                    minutes_ += h * 60;
                    hours_ -= h;
                }

                hours_ += minutes_ / 60;
                minutes_ %= 60;
                if (hours_ < 0)
                    hours_ += 24;

                hours_ %= 24;

                return str();
            }

            std::string minus(int min) {
                return plus(-min);
            }

            std::string str() const {
                return int_to_padded_str(hours_) + ":" +
                       int_to_padded_str(minutes_);
            }

            operator std::string() const {
                return str();
            }

            friend bool operator==(const time& l, const time& r) {
                return l.hours_ == r.hours_ &&
                       l.minutes_ == r.minutes_;
            }

            friend bool operator!=(const time& l, const time& r) {
                return l.hours_ != r.hours_ ||
                       l.minutes_ != r.minutes_;
            }

            private:
                int hours_;
                int minutes_;
        };

        time at(int hours, int minutes = 0) {
            return time(hours, minutes);
        }

        bool operator==(const time&, const time&);
        bool operator!=(const time&, const time&);
    }
}

#endif


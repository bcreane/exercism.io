#if !defined(MEETUP_H)
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>

namespace bg = boost::gregorian;
namespace bdt = boost::date_time;

namespace meetup {
    
    struct scheduler {
    public:
        scheduler(bg::date::month_type month, bg::date::year_type year)
            : year_(year),
              month_(month)
        {}

        // DAYteenth
        bg::date monteenth() const {
            return teenth_day(bdt::weekdays::Monday);
        }
        bg::date tuesteenth() const {
            return teenth_day(bdt::weekdays::Tuesday);
        }
        bg::date wednesteenth() const {
            return teenth_day(bdt::weekdays::Wednesday);
        }
        bg::date thursteenth() const {
            return teenth_day(bdt::weekdays::Thursday);
        }
        bg::date friteenth() const {
            return teenth_day(bdt::weekdays::Friday);
        }
        bg::date saturteenth() const {
            return teenth_day(bdt::weekdays::Saturday);
        }
        bg::date sunteenth() const {
            return teenth_day(bdt::weekdays::Sunday);
        }

        // first_DAY
        bg::date first_monday() const {
            return first_weekday(bdt::weekdays::Monday);
        }
        bg::date first_tuesday() const {
            return first_weekday(bdt::weekdays::Tuesday);
        }
        bg::date first_wednesday() const {
            return first_weekday(bdt::weekdays::Wednesday);
        }
        bg::date first_thursday() const {
            return first_weekday(bdt::weekdays::Thursday);
        }
        bg::date first_friday() const {
            return first_weekday(bdt::weekdays::Friday);
        }
        bg::date first_saturday() const {
            return first_weekday(bdt::weekdays::Saturday);
        }
        bg::date first_sunday() const {
            return first_weekday(bdt::weekdays::Sunday);
        }

        // second_DAY
        bg::date second_monday() const {
            return second_weekday(bdt::weekdays::Monday);
        }
        bg::date second_tuesday() const {
            return second_weekday(bdt::weekdays::Tuesday);
        }
        bg::date second_wednesday() const {
            return second_weekday(bdt::weekdays::Wednesday);
        }
        bg::date second_thursday() const {
            return second_weekday(bdt::weekdays::Thursday);
        }
        bg::date second_friday() const {
            return second_weekday(bdt::weekdays::Friday);
        }
        bg::date second_saturday() const {
            return second_weekday(bdt::weekdays::Saturday);
        }
        bg::date second_sunday() const {
            return second_weekday(bdt::weekdays::Sunday);
        }

        // third_DAY
        bg::date third_monday() const {
            return third_weekday(bdt::weekdays::Monday);
        }
        bg::date third_tuesday() const {
            return third_weekday(bdt::weekdays::Tuesday);
        }
        bg::date third_wednesday() const {
            return third_weekday(bdt::weekdays::Wednesday);
        }
        bg::date third_thursday() const {
            return third_weekday(bdt::weekdays::Thursday);
        }
        bg::date third_friday() const {
            return third_weekday(bdt::weekdays::Friday);
        }
        bg::date third_saturday() const {
            return third_weekday(bdt::weekdays::Saturday);
        }
        bg::date third_sunday() const {
            return third_weekday(bdt::weekdays::Sunday);
        }

        // fourth_DAY
        bg::date fourth_monday() const {
            return fourth_weekday(bdt::weekdays::Monday);
        }
        bg::date fourth_tuesday() const {
            return fourth_weekday(bdt::weekdays::Tuesday);
        }
        bg::date fourth_wednesday() const {
            return fourth_weekday(bdt::weekdays::Wednesday);
        }
        bg::date fourth_thursday() const {
            return fourth_weekday(bdt::weekdays::Thursday);
        }
        bg::date fourth_friday() const {
            return fourth_weekday(bdt::weekdays::Friday);
        }
        bg::date fourth_saturday() const {
            return fourth_weekday(bdt::weekdays::Saturday);
        }
        bg::date fourth_sunday() const {
            return fourth_weekday(bdt::weekdays::Sunday);
        }

        // last_DAY
        bg::date last_monday() const {
            return last_weekday(bdt::weekdays::Monday);
        }
        bg::date last_tuesday() const {
            return last_weekday(bdt::weekdays::Tuesday);
        }
        bg::date last_wednesday() const {
            return last_weekday(bdt::weekdays::Wednesday);
        }
        bg::date last_thursday() const {
            return last_weekday(bdt::weekdays::Thursday);
        }
        bg::date last_friday() const {
            return last_weekday(bdt::weekdays::Friday);
        }
        bg::date last_saturday() const {
            return last_weekday(bdt::weekdays::Saturday);
        }
        bg::date last_sunday() const {
            return last_weekday(bdt::weekdays::Sunday);
        }

    private:
        bg::date first_weekday(bdt::weekdays day) const {
            return bg::first_day_of_the_week_in_month(day, month_).get_date(year_);
        }
        bg::date second_weekday(bdt::weekdays day) const {
            return nth_weekday(bg::nth_day_of_the_week_in_month::second, day);
        }
        bg::date third_weekday(bdt::weekdays day) const {
            return nth_weekday(bg::nth_day_of_the_week_in_month::third, day);
        }
        bg::date fourth_weekday(bdt::weekdays day) const {
            return nth_weekday(bg::nth_day_of_the_week_in_month::fourth, day);
        }
        bg::date last_weekday(bdt::weekdays day) const {
            return bg::last_day_of_the_week_in_month(day, month_).get_date(year_);
        }
        bg::date teenth_day(bdt::weekdays day) const {
            return bg::first_day_of_the_week_after(day).get_date({year_, month_, 12});
        }
        bg::date nth_weekday(bg::nth_day_of_the_week_in_month::week_num n, bdt::weekdays day) const {
            return bg::nth_day_of_the_week_in_month(n, day, month_).get_date(year_);
        }

        const bg::date::year_type year_;
        const bg::date::month_type month_;
    };
}

#endif

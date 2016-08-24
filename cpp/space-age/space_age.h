#if !defined (SPACE_AGE_H)
#define SPACE_AGE_H

#include <cstdint>

namespace {
    const double earth_seconds_in_a_year = 31557600;
    const double mercury_orbital_period =  0.2408467;
    const double venus_orbital_period = 0.61519726;

    const double mars_orbital_period = 1.8808158;
    const double jupiter_orbital_period = 11.862615;
    const double saturn_orbital_period = 29.447498;
    const double uranus_orbital_period = 84.016846;
    const double neptune_orbital_period = 164.79132;
}

namespace space_age {
    struct space_age {
        space_age(uint64_t age_in_seconds)
          : age_in_seconds_(age_in_seconds) {}
        
        uint64_t seconds() const {
            return age_in_seconds_;
        }

        double on_earth() const {
            return static_cast<double>(age_in_seconds_) / earth_seconds_in_a_year;
        }

        double on_mercury() const {
            return on_earth() / mercury_orbital_period;
        }

        double on_venus() const {
            return on_earth() / venus_orbital_period;
        }
        
        double on_mars() const {
            return on_earth() / mars_orbital_period;
        }
        
        double on_jupiter() const {
            return on_earth() / jupiter_orbital_period;
        }
        
        double on_saturn() const {
            return on_earth() / saturn_orbital_period;
        }
        
        double on_uranus() const {
            return on_earth() / uranus_orbital_period;
        }
        
        double on_neptune() const {
            return on_earth() / neptune_orbital_period;
        }
    
    private:
        uint64_t age_in_seconds_;
    };
}
#endif

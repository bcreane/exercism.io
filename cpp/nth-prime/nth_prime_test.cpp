#include "nth_prime.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <stdexcept>

BOOST_AUTO_TEST_CASE(first)
{
    BOOST_REQUIRE_EQUAL(2, prime::nth(1));
}

BOOST_AUTO_TEST_CASE(second)
{
    BOOST_REQUIRE_EQUAL(3, prime::nth(2));
}

BOOST_AUTO_TEST_CASE(sixth)
{
    BOOST_REQUIRE_EQUAL(13, prime::nth(6));
}

#if 0
BOOST_AUTO_TEST_CASE(big_prime)
{
    BOOST_REQUIRE_EQUAL(104743, prime::nth(10001));
}
#endif

BOOST_AUTO_TEST_CASE(weird_case)
{
    BOOST_REQUIRE_THROW(prime::nth(0), std::domain_error);
}


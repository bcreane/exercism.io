#include "grade_school.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "../boost_hack.h"
#include "require_equal_containers.h"

using namespace std;

struct school_fixture
{
    grade_school::school school_;
};

BOOST_FIXTURE_TEST_SUITE(school_suite, school_fixture);

BOOST_AUTO_TEST_CASE(a_new_school_has_an_empty_roster)
{
    BOOST_REQUIRE(school_.roster().empty());
}

BOOST_AUTO_TEST_CASE(adding_a_student_adds_them_to_the_roster_for_the_given_grade)
{
    school_.add("Aimee", 2);

    const auto actual = school_.roster();

    const map<int, vector<string>> expected{{2, {"Aimee"}}};
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(adding_more_students_to_the_same_grade_adds_them_to_the_roster)
{
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);

    const auto actual = school_.roster();

    const map<int, vector<string>> expected{{2, {"Blair", "James", "Paul"}}};
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(adding_students_to_different_grades_adds_them_to_the_roster)
{
    school_.add("Chelsea", 3);
    school_.add("Logan", 7);

    const auto actual = school_.roster();

    const map<int, vector<string>> expected{{3, {"Chelsea"}}, {7, {"Logan"}}};
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(grade_returns_the_students_in_that_grade_in_alphabetical_order)
{
    school_.add("Bradley", 5);
    school_.add("Franklin", 5);
    school_.add("Jeff", 1);

    const auto actual = school_.grade(5);

    const vector<string> expected{"Bradley", "Franklin"};
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(grade_returns_an_empty_array_if_there_are_no_students_in_that_grade)
{
    const auto actual = school_.grade(1);

    BOOST_REQUIRE(actual.empty());
}

BOOST_AUTO_TEST_CASE(the_student_names_in_each_grade_in_the_roster_are_sorted)
{
    school_.add("Jennifer", 4);
    school_.add("Kareem", 6);
    school_.add("Christopher", 4);
    school_.add("Kyle", 3);

    const auto actual = school_.roster();

    const map<int, vector<string>> expected{
            {3, {"Kyle"}},
            {4, {"Christopher", "Jennifer"}},
            {6, {"Kareem"}}
        };
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_SUITE_END();

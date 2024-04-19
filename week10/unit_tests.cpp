#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>
#include <cmath>

#include "doctest.h"
#include "Vehicle.h"
#include "Electric.h"
#include "Gasoline.h"
#include "Hybrid.h"

using namespace std;

TEST_CASE("hybrid") {
    SUBCASE("efficiency") {
        Hybrid h = Hybrid(0, 1, 1, 2, 2);
        CHECK(h.get_efficiency() == 2);
    }

    SUBCASE("cost_of_fuel") {
        Hybrid h = Hybrid(0, 1, 1, 2, 2);
        CHECK(h.get_cost_of_fuel() == 2);
    }

    SUBCASE("zero miles per charge/gallon") {
        Hybrid h = Hybrid(0, 1, 1, 0, 0);
        CHECK(h.get_efficiency() == 0);
    }

    SUBCASE("zero cost per charge/gallon") {
        Hybrid h = Hybrid(0, 0, 0, 1, 1);
        //expecting result of divide by zero to be either infinite or nan,
        //depending on local machine
        bool result = isinf(h.get_efficiency()) || isnan(h.get_efficiency());
        CHECK(result);
    }
}
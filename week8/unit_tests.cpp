#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include "doctest.h"
#include "double_vector.h"

TEST_CASE("double_vector") {
    SUBCASE("square") {
        double x = 1.0;
        double y = 0.0;
        double z = 1.52;
        
        CHECK(square(x) == 1.0);
        CHECK(square(y) == 0.0);
        CHECK(square(z) == 2.3104);
    }

    SUBCASE("dot_product") {
        double_vector zero_vector = double_vector(0.0, 0.0);
        double_vector one_vector = double_vector(1.0, 1.0);
        
        CHECK(dot_product(zero_vector, zero_vector) == 0.0);
        CHECK(dot_product(zero_vector, one_vector) == 0.0);
        CHECK(dot_product(one_vector, one_vector) == 2.0);

        double_vector test_vector = double_vector(3.0, 4.0);

        CHECK(dot_product(test_vector, zero_vector) == 0.0);
        CHECK(dot_product(test_vector, one_vector) == 7.0);
        CHECK(dot_product(test_vector, test_vector) == 25.0);
    }

    SUBCASE("magnitude") {
        double_vector zero_vector = double_vector(0.0, 0.0);
        double_vector one_vector = double_vector(1.0, 1.0);
        double_vector test_vector = double_vector(4.0, 9.0);

        CHECK(magnitude(zero_vector) == 0.0);
        CHECK(magnitude(one_vector) == sqrt(2.0));
        CHECK(magnitude(test_vector) == sqrt(97.0));
    }
}
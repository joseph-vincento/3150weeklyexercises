#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "doctest.h"
#include "int_vector.h"

TEST_CASE("int_vector") {
    SUBCASE("default constructor") {
        int_vector dc_vec;
        CHECK(dc_vec.id == -1);
        CHECK(dc_vec.from == 0);
        CHECK(dc_vec.to == 0);
    };

    SUBCASE("copy constructor") {
        int_vector vec1;
        vec1.id = 1;
        vec1.from = 2;
        vec1.to = 3;
        int_vector vec2(vec1);

        CHECK(vec2.id == vec1.id);
        CHECK(vec2.from == vec1.from);
        CHECK(vec2.to == vec1.to);
    }

    SUBCASE("read from empty file") {
        vector<int_vector> vec_0 = read_int_vectors("test_empty_file.txt");
        CHECK(vec_0.empty());
    }
};
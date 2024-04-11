#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "triangle.h"

TEST_CASE("triangle") {
    SUBCASE("default constructor") {
        Triangle t;

        CHECK(t.get_x() == 0);
        CHECK(t.get_y() == 0);
        CHECK(t.get_z() == 0);
    }

    SUBCASE("copy constructor") {
        Triangle t1;
        t1.set_x(6.0);
        t1.set_y(6.0);
        t1.set_z(6.0);

        Triangle t2 = Triangle(t1);

        CHECK(t1.get_x() == t2.get_x());
        CHECK(t1.get_y() == t2.get_y());
        CHECK(t1.get_z() == t2.get_z());
    }

    SUBCASE("arguement constructor") {
        Triangle t = Triangle(6.0, 6.0, 6.0);

        CHECK(t.get_x() == 6.0);
        CHECK(t.get_y() == 6.0);
        CHECK(t.get_z() == 6.0);
    }

    SUBCASE("edge length") {
        Triangle t = Triangle(3, 4, 6);


        CHECK(t.get_edge_length(t.get_x(), t.get_y()) == 1);
        CHECK(t.get_edge_length(t.get_x(), t.get_z()) == 3);
        CHECK(t.get_edge_length(t.get_y(), t.get_z()) == 2);
    } 

    SUBCASE("semiperimeter") {
        Triangle t = Triangle(3, 4, 6);
        double d12 = t.get_edge_length(t.get_x(), t.get_y());
        double d13 = t.get_edge_length(t.get_x(), t.get_z());
        double d23 = t.get_edge_length(t.get_y(), t.get_z());

        CHECK(t.get_semi_perimeter(d12, d13, d23) == 3);
    }

    SUBCASE("area") {
        Triangle t = Triangle(3, 4, 6);

        CHECK(t.get_area() >= 0.790569);
    }
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cmath>

#include "doctest.h"
#include "triangle3d.h"
#include "point3d.h"

// for comparison of doubles
bool is_equal(double n, double target, double tolerance) {
            return fabs(n - target) < tolerance;
};

TEST_CASE("triangle3d") {
    SUBCASE("calc_area") {
        Triangle3d t1 = Triangle3d();

        Point3d p1 = Point3d(1, 1, 1);
        Point3d p2 = Point3d(1, 1, 1);
        Point3d p3 = Point3d(1, 1, 1);
        Triangle3d t2 = Triangle3d(p1, p2, p3);

        Point3d p1_2 = Point3d(1, 5, 3);
        Point3d p2_2 = Point3d(7, 8, 2);
        Point3d p3_2 = Point3d(4, 6, 9);
        Triangle3d t3 = Triangle3d(p1_2, p2_2, p3_2);

        // // default constructors, all points set to (0, 0, 0), area = 0
        CHECK(t1.calc_area() == 0);

        // All points equal (1, 1, 1), area = 0
        CHECK(t2.calc_area() == 0);

        // typical use case
        double t3_area = t3.calc_area();
        double expected_t3_area = 21.7428;
        double tolerance = 1e-4;
        CHECK(is_equal(t3_area, expected_t3_area, tolerance));
    }

    SUBCASE("calc_point_distance") {
        Triangle3d t1 = Triangle3d();

        Point3d p1 = Point3d(1, 1, 1);
        Point3d p2 = Point3d(1, 1, 1);
        Point3d p3 = Point3d(1, 1, 1);
        Triangle3d t2 = Triangle3d(p1, p2, p3);

        Point3d p1_2 = Point3d(1, 5, 3);
        Point3d p2_2 = Point3d(7, 8, 2);
        Point3d p3_2 = Point3d(4, 6, 9);
        Triangle3d t3 = Triangle3d(p1_2, p2_2, p3_2);

        // default constructors, all points set to (0, 0, 0), distance = 0
        CHECK(t1.calc_point_distance(t1.get_p1(), t1.get_p2()) == 0);
        CHECK(t1.calc_point_distance(t1.get_p1(), t1.get_p3()) == 0);
        CHECK(t1.calc_point_distance(t1.get_p2(), t1.get_p3()) == 0);

        // All points equal (1, 1, 1), distance = 0
        CHECK(t2.calc_point_distance(t2.get_p1(), t2.get_p2()) == 0);
        CHECK(t2.calc_point_distance(t2.get_p1(), t2.get_p3()) == 0);
        CHECK(t2.calc_point_distance(t2.get_p2(), t2.get_p3()) == 0);

        //typical use case
        //double epsilon = 0.00001d;
        double d12 = t3.calc_point_distance(t3.get_p1(), t3.get_p2());
        double d13 = t3.calc_point_distance(t3.get_p1(), t3.get_p3());
        double d23 = t3.calc_point_distance(t3.get_p2(), t3.get_p3());
        double expected_d12 = 6.78233;
        double expected_d13 = 6.78233;
        double expected_d23 = 7.87401;
        double tolerance = 1e-5;

        CHECK(is_equal(d12, expected_d12, tolerance));
        CHECK(is_equal(d13, expected_d13, tolerance));
        CHECK(is_equal(d23, expected_d23, tolerance));
    }
}

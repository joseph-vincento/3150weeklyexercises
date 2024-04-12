#ifndef _TRIANGLE_3D_H_
#define _TRIANGLE_3D_H_

#include <iostream>
#include "point3d.h"

using namespace std;

class Triangle3d {
    private:
        Point3d p1;
        Point3d p2;
        Point3d p3;
    
    public:
        // Class constructors
        Triangle3d() : p1(Point3d()), p2(Point3d()), p3(Point3d()) {};
        Triangle3d(const Triangle3d &t) : p1(t.p1), p2(t.p2), p3(t.p3) {};
        Triangle3d(const Point3d &p3d1, const Point3d &p3d2, const Point3d &p3d3): p1(p3d1), p2(p3d2), p3(p3d3) {};
        ~Triangle3d() {};

        // Class getters
        Point3d get_p1() const {return p1;}
        Point3d get_p2() const {return p2;}
        Point3d get_p3() const {return p3;}

        // Class setters
        void set_p1(const Point3d &p3d) {p1 = p3d;}
        void set_p2(const Point3d &p3d) {p2 = p3d;}
        void set_p3(const Point3d &p3d) {p3 = p3d;}

        // Area functions
        double calc_area();
        double calc_point_distance(const Point3d &p1, const Point3d &p2);
};

// Triangle ostream operator
ostream &operator<<(ostream &out_stream, const Triangle3d &t);

#endif
#ifndef _POINT_3D_H_
#define _POINT_3D_H_

#include <iostream>

using namespace std;

class Point3d {
    private:
        double x;
        double y;
        double z;
    
    public:
        // Class constructors
        Point3d() : x(0.0), y(0.0), z(0.0) {};
        Point3d(const Point3d &p3d) : x(p3d.x), y(p3d.y), z(p3d.z) {};
        Point3d(const double &p_x, const double &p_y, const double &p_z) : x(p_x), y(p_y), z(p_z) {};
        ~Point3d() {};

        // Class getters
        double get_x() const {return x;}
        double get_y() const {return y;}
        double get_z() const {return z;}

        // Class setters
        void set_x(const double &n) {x = n;}
        void set_y(const double &n) {y = n;}
        void set_z(const double &n) {z = n;}
};

// Point3d ostream operator
ostream &operator<<(ostream &out_stream, const Point3d &p3d);

#endif
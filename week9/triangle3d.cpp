#include <iostream>
#include <cmath>
#include <cstdlib>

#include "triangle3d.h"

using namespace std;

double Triangle3d::calc_area() {
    double d12 = calc_point_distance(this->get_p1(), this->get_p2());
    double d13 = calc_point_distance(this->get_p1(), this->get_p3());
    double d23 = calc_point_distance(this->get_p2(), this->get_p3());

    double s = (d12 + d13 + d23) / 2;

    double area = sqrt(s * (s - d12) * (s - d13) * (s - d23));
    return area;
}

double Triangle3d::calc_point_distance(const Point3d &p1, const Point3d &p2) {
    double x_diff = p1.get_x() - p2.get_x();
    double y_diff = p1.get_y() - p2.get_y();
    double z_diff = p1.get_z() - p2.get_z();

    double distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2));
    return distance;
}

ostream &operator<<(ostream &out_stream, const Triangle3d &t) {
    out_stream << "Point 1: x = " << t.get_p1().get_x() << ", y = " << t.get_p1().get_y() << ", z = " << t.get_p1().get_z() << endl
        << "Point 2: x = " << t.get_p2().get_x() << ", y = " << t.get_p2().get_y() << ", z = " << t.get_p2().get_z() << endl
        << "Point 3: x = " << t.get_p3().get_x() << ", y = " << t.get_p3().get_y() << ", z = " << t.get_p3().get_z() << endl;
    return out_stream;
}   
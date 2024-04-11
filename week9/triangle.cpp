#include <iostream>
#include <cstdlib>
#include <cmath>

#include "triangle.h"

using namespace std;

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Triangle::Triangle(const Triangle& t) {
    x = t.x;
    y = t.y;
    z = t.z;
}

Triangle::Triangle(double n, double i, double j) {
    x = n;
    y = i;
    z = j;
}

double Triangle::get_area() {
    double d12 = get_edge_length(get_x(), get_y());
    double d13 = get_edge_length(get_x(), get_z());
    double d23 = get_edge_length(get_x(), get_z());

    double s = get_semi_perimeter(d12, d13, d23);

    return sqrt((s - d12) * (s - d13) * (s - d23));
}

double Triangle::get_edge_length(double i, double j) {
    return abs(i - j);
}

double Triangle::get_semi_perimeter(double d12, double d13, double d23) {
    return (d12 + d13 + d23) / 2;
}

ostream &operator<<(ostream &out_stream, const Triangle &t) {
    out_stream << "x = " << t.get_x() << ", "
        << "y = " << t.get_y() << ", "
        << "z = " << t.get_z();
    
    return out_stream;
}
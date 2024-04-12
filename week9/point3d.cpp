#include <iostream>

#include "point3d.h"

using namespace std;

ostream &operator<<(ostream &out_stream, const Point3d &p3d) {
    out_stream << "x = " << p3d.get_x() << ", "
        << "y = " << p3d.get_y() << ", "
        << "z = " << p3d.get_z();
    
    return out_stream;
}
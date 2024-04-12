#include "point3d.h"
#include "triangle3d.h"

using namespace std;

int main() {
    // Example taken from https://planetcalc.com/218/
    Point3d p1 = Point3d(1, 1, 0);
    Point3d p2 = Point3d(-2 , 4 , 0);
    Point3d p3 = Point3d(-2, -2, 0);

    Triangle3d t = Triangle3d();
    t.set_p1(p1);
    t.set_p2(p2);
    t.set_p3(p3);

    cout << "For the 3d triangle with points:" << endl;
    cout << t;
    cout << "The area of the triangle is " << t.calc_area() << endl;;

    return 0;
}
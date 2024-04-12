#include "point3d.h"
#include "triangle3d.h"

using namespace std;

void get_user_input() {
    double x;
    double y;
    double z;
    Point3d points[3];
    
    for(int i = 1; i < 4; i++) {
        cout << "For point " << i << ", enter a value for x: ";
        cin >> x;
        cout << "For point " << i << ", enter a value for y: ";
        cin >> y;
        cout << "For point " << i << ", enter a value for z: ";
        cin >> z;

        points[i - 1] = Point3d(x, y, z);
    }

    Triangle3d t = Triangle3d(points[0], points[1], points[2]);
    
    cout << "For the 3d triangle with points:" << endl;
    cout << t;
    cout << "The area of the triangle is " << t.calc_area() << endl;
}

int main() {
    // Example taken from https://planetcalc.com/218/
    Point3d p1 = Point3d(1, 1, 0);
    Point3d p2 = Point3d(-2 , 4 , 0);
    Point3d p3 = Point3d(-2, -2, 0);

    Triangle3d t = Triangle3d(p1, p2, p3);

    cout << "Demo" << endl;
    cout << "For the 3d triangle with points:" << endl;
    cout << t;
    cout << "The area of the triangle is " << t.calc_area() << endl;

    bool cont = true;
    char in;

    while(cont) {
        cout << "Try your own? (y/n): ";
        cin >> in;

        if (in == 'y' || in == 'Y')
            get_user_input();
        else
            cont = false;
    }

    return 0;
}
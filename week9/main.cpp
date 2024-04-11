#include "triangle.h"

using namespace std;

int main() {
    Triangle t;
    t.set_x(2.0);
    t.set_y(4.0);
    t.set_z(6.0);
    cout << "First triangle" << endl;
    cout << t << endl;
    cout << t.get_area() << endl;

    Triangle t2 = Triangle(t);
    cout << "Copy of first triangle" << endl;
    cout << t2 << endl;
    cout << t2.get_area() << endl;

    Triangle t3(6.9, 15.0, 17.0);
    cout << "Second triangle" << endl;
    cout << t3 << endl;
    cout << t3.get_area() << endl;

    return 0;
}
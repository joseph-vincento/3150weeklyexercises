#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <iostream>

using namespace std;

struct Triangle {
    private:
        double x;
        double y;
        double z;
    
    public:
        // Class constructors
        Triangle();
        Triangle(const Triangle& t);
        Triangle(double n, double i, double j);
        ~Triangle() {};

        // Class getters
        double get_x() const {return x;}
        double get_y() const {return y;}
        double get_z() const {return z;}

        // Class setters
        void set_x(const double n) {x = n;}
        void set_y(const double n) {y = n;}
        void set_z(const double n) {z = n;};  

        // Area functions
        double get_area();
        double get_edge_length(double i, double j);
        double get_semi_perimeter(double d12, double d13, double d23);

};

// Triangle ostream operator
ostream &operator<<(ostream &out_stream, const Triangle &t);

#endif
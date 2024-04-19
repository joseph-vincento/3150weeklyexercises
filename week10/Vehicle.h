#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

using namespace std;

class Vehicle {
    protected:
        double weight;
    public:
        Vehicle();
        Vehicle(double w) : weight(w) {
            cout << "Vehicle contructor" << endl;
        };

        virtual void start() {
            cout << "Vehicle starting" << endl;
        }

        virtual void stop() {
            cout << "Vehicle stopping" << endl;
        }

        virtual double get_cost_of_fuel() { return 0; }
        virtual double get_weight() { return weight; }
};

#endif

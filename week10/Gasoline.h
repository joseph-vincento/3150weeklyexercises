#ifndef _GASOLINE_H_
#define _GASOLINE_H_

#include <iostream>

using namespace std;

class Gasoline : virtual public Vehicle{
    protected:
        double efficiency;
        double miles_per_gallon;
        double cost_of_fuel;
    public:
        Gasoline(double w, double fuel_cost, double mpg) : 
            Vehicle(w), 
            miles_per_gallon(mpg),
            cost_of_fuel(fuel_cost) {
            cout << "Gasoline constructor" << endl;
            efficiency = miles_per_gallon / fuel_cost;
        };

        void start() override {
            cout << "Gasoline starting" << endl;
        }

        void stop() override {
            cout << "Gasoline stopping" << endl;
        }

        double get_weight() override { return weight; }
        double get_cost_of_fuel() override { return cost_of_fuel; }
        double get_miles_per_gallon() {return miles_per_gallon; }
        virtual double get_efficiency() { return efficiency; }
        
};

#endif
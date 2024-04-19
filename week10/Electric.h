#ifndef _ELECTRIC_H_
#define _ELECTRIC_H_

#include <iostream>

using namespace std;

class Electric : virtual public Vehicle {
    protected:
        double efficiency;
        double miles_per_charge;
        double cost_of_charge;
    public:
        Electric(double w, double electricity_cost, double mpc) : 
            Vehicle(w), 
            miles_per_charge(mpc),
            cost_of_charge(electricity_cost) {
            cout << "Electric constructor" << endl;
            efficiency = miles_per_charge / cost_of_charge;
        };

        void start() override {
            cout << "Electric starting" << endl;
        }

        void stop() override {
            cout << "Electric stopping" << endl;
        }

        double get_weight() override { return weight; }
        double get_cost_of_fuel() override { return cost_of_charge; }
        double get_miles_per_charge() { return miles_per_charge; }
        virtual double get_efficiency() { return efficiency; }
};

#endif
#ifndef _HYBRID_H_
#define _HYBRID_H_

class Hybrid : virtual public Electric, virtual public Gasoline {
    protected:
        double efficiency;
    public:
        Hybrid(double w, double fuel_cost, double electricity_cost, double mpg, double mpc) : 
            Vehicle(w), 
            Electric(w, electricity_cost, mpc), 
            Gasoline(w, fuel_cost, mpg) {
            cout << "Hybrid constructor" << endl;
            efficiency = 
                (Electric::get_miles_per_charge() + Gasoline::get_miles_per_gallon()) / 
                (Electric::get_cost_of_fuel() + Gasoline::get_cost_of_fuel());
        }

        void start() override {
            cout << "Hybrid starting" << endl;
        }

        void stop() override {
            cout << "Hybrid stopping" << endl;
        }

        double get_weight() override { return weight; }
        double get_cost_of_fuel() override { return Gasoline::get_cost_of_fuel() + Electric::get_cost_of_fuel(); }
        double get_efficiency() override { return efficiency; }
};

#endif
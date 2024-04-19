#include <iostream>

#include "Vehicle.h"
#include "Electric.h"
#include "Gasoline.h"
#include "Hybrid.h"

using namespace std;

int main() {
    double weight;
    double cost_of_fuel;
    double miles_per_gallon;
    double cost_of_charge;
    double miles_per_charge;
    
    cout << "Enter the weight of the hybrid car: ";
    cin >> weight;
    cout << "Enter the cost per gallon of gasoline fuel: ";
    cin >> cost_of_fuel;
    cout << "Enter the expected mileage per gallon of gasoline fuel: ";
    cin >> miles_per_gallon;
    cout << "Enter the cost per kWh of the elecricity: ";
    cin >> cost_of_charge;
    cout << "Enter the expected mileage per kWh of battery charge: ";
    cin >> miles_per_charge;
    
    cout << "Creating the hybrid..." << endl;
    Hybrid h = Hybrid(weight, cost_of_fuel, cost_of_charge, miles_per_gallon, miles_per_charge);

    cout << "Starting the hybrid.." << endl;
    h.start();
    cout << endl;
    cout << "The hybrid's cost of fuel per unit is $" << h .Gasoline::get_cost_of_fuel() << endl;
    cout << "The hybrid has an efficiency rating of " << h.Gasoline::get_efficiency() << endl;
    cout << endl;
    cout << "Stopping the hybrid.." << endl;

    return 0;
}
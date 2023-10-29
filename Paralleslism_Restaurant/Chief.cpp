#include "Chief.h"
#include "Cook.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Chief::Chief(Cook* cook) : cook(cook) 
{

}

void Chief::composeMeal(const vector<int>& ingredients) 
{
    cout << "Chief composes a meal from ingredients: ";
    for (int ingredient : ingredients) 
    {
        cout << ingredient << " ";
    }
    cout << endl;
}

void Chief::exitRestaurant(int customerId) 
{
    this_thread::sleep_for(chrono::seconds(2)); // Simulate customer's time in the restaurant
    cout << "Customer " << customerId << " exits the restaurant." << endl;
}


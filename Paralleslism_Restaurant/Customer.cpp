#include "Customer.h"
#include "Waiter.h"
#include "Chief.h"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

Customer::Customer(int id, Waiter* waiter, Chief* chief) : id(id), waiter(waiter), chief(chief) 
{

}

void Customer::run() 
{
    vector<int> ingredients;
    for (int i = 1; i <= 3; ++i) 
    {
        ingredients.push_back(rand() % 10 + 1); // Randomly select 3 ingredients from 10
    }

    cout << "Customer " << id << " orders a meal with ingredients: ";
    for (int ingredient : ingredients) 
    {
        cout << ingredient << " ";
    }
    cout << endl;

    waiter->placeOrder(id, ingredients);

    this_thread::sleep_for(chrono::seconds(2)); // Simulate eating
    cout << "Customer " << id << " has eaten the meal." << endl;

    chief->exitRestaurant(id);
}

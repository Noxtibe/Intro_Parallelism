#include "Customer.h"
#include "Waiter.h"
#include "Chief.h"
#include "Cook.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

Customer::Customer(int id, Waiter* waiter, Chief* chief) : id(id), waiter(waiter), chief(chief)
{
}

void Customer::dine() 
{
    std::vector<int> ingredients;

    // Simulate ordering a meal with 3 random ingredients out of 10
    for (int i = 0; i < 3; ++i) 
    {
        ingredients.push_back(std::rand() % 10 + 1);
    }

    std::cout << "Customer " << id << " orders a meal with ingredients: ";
    for (int ingredient : ingredients) 
    {
        std::cout << ingredient << " ";
    }
    std::cout << std::endl;

    waiter->placeOrder(id, ingredients);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    cook->prepareIngredients(ingredients);

    chief->composeMeal(ingredients);

    waiter->serveMeal(id, ingredients);

    // Simulate eating
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Customer " << id << " has eaten the meal." << std::endl;

    chief->exitRestaurant(id);
}

#include "Chief.h"
#include "Cook.h"
#include <iostream>
#include <thread>
#include <chrono>

Chief::Chief(Cook* cook) : cook(cook) 
{
}

void Chief::composeMeal(const std::vector<int>& ingredients) 
{
    std::cout << "Chief composes a meal from ingredients : ";
    for (int ingredient : ingredients) 
    {
        std::cout << ingredient << " ";
    }
    std::cout << std::endl;
}

void Chief::exitRestaurant(int customerId) 
{
    // Simulate customer's time in the restaurant
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Customer " << customerId << " exits the restaurant." << std::endl;
}

void Chief::run() 
{
}

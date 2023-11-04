#include "Cook.h"
#include "Waiter.h"
#include "Chief.h"
#include <iostream>
#include <thread>
#include <chrono>

Cook::Cook(Waiter* waiter, Chief* chief) : waiter(waiter), chief(chief) 
{
}

void Cook::prepareIngredients(const std::vector<int>& ingredients) 
{
    std::cout << "Cook prepares ingredients: ";
    for (int ingredient : ingredients) 
    {
        std::cout << ingredient << " ";
    }
    std::cout << std::endl;

    // Simulate ingredient preparation
    std::this_thread::sleep_for(std::chrono::seconds(2));

    //chief->composeMeal(ingredients);
}

void Cook::run() 
{
    // Cook's main loop (if necessary)
}

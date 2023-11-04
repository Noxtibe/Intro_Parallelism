#include "Waiter.h"
#include "Cook.h"
#include "Chief.h"
#include <iostream>
#include <thread>
#include <chrono>

Waiter::Waiter(Cook* cook, Chief* chief) : cook(cook), chief(chief) 
{
}

void Waiter::placeOrder(int customerId, const std::vector<int>& ingredients) 
{
    std::lock_guard<std::mutex> lock(mtx);
    orders.push_back(std::make_pair(customerId, ingredients));

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Waiter take the order of Customer : " << customerId << std::endl;

}

void Waiter::serveMeal(int customerId, const std::vector<int>& ingredients) 
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Waiter serves the meal to Customer " << customerId << std::endl;
}

void Waiter::run() 
{
    while (true) 
    {
        if (!orders.empty()) 
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (!orders.empty()) 
            {
                auto order = orders.front();
                orders.erase(orders.begin());
                std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate meal preparation
                serveMeal(order.first, order.second);
            }
        }
    }
}
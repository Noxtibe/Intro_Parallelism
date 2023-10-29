// Waiter.cpp
#include "Waiter.h"
#include "Chief.h"
#include "Cook.h"
#include "Customer.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Waiter::Waiter(Cook* cook, Chief* chief) : cook(cook), chief(chief) 
{

}

void Waiter::run() 
{
    while (true) 
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return !orders.empty(); });
        if (!orders.empty()) 
        {
            auto order = orders.front();
            orders.pop();
            lock.unlock();
            this_thread::sleep_for(chrono::seconds(2)); // Simulate meal preparation
            serveMeal(order.first, order.second);
        }
    }
}

void Waiter::placeOrder(int customerId, const vector<int>& ingredients) 
{
    unique_lock<mutex> lock(mtx);
    orders.push(make_pair(customerId, ingredients));
    lock.unlock();
    cv.notify_one();
}

void Waiter::serveMeal(int customerId, const vector<int>& ingredients) 
{
    cout << "Waiter serves the meal to Customer " << customerId << endl;
    cook->ingredientPreparation(ingredients);
}


#include "Cook.h"
#include "Chief.h"
#include "Waiter.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Cook::Cook(Chief* chief) : chief(chief) 
{

}

void Cook::run() 
{
    while (true) 
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return !preparationQueue.empty(); });
        if (!preparationQueue.empty()) {
            vector<int> ingredients = preparationQueue.front();
            preparationQueue.pop();
            lock.unlock();
            this_thread::sleep_for(chrono::seconds(1)); // Simulate ingredient preparation
            ingredientPreparation(ingredients);
        }
    }
}

void Cook::ingredientPreparation(const vector<int>& ingredients) 
{
    cout << "Cook prepares ingredients: ";
    for (int ingredient : ingredients) 
    {
        cout << ingredient << " ";
    }
    cout << endl;

    if (ingredients.size() == 3) 
    {
        chief->composeMeal(ingredients);
    }
}


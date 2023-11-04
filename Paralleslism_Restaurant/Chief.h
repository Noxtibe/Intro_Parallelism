#pragma once

#include <vector>
#include <mutex>

class Cook;

class Chief 
{
public:

    Chief(Cook* cook);
    void composeMeal(const std::vector<int>& ingredients);
    void exitRestaurant(int customerId);
    void run();

private:

    Cook* cook;
};

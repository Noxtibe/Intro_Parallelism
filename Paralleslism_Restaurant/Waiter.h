#pragma once

#include <vector>
#include <queue>
#include <mutex>
#include <iostream>

class Cook;
class Chief;

class Waiter 
{
public:

    Waiter(Cook* cook, Chief* chief);
    void placeOrder(int customerId, const std::vector<int>& ingredients);
    void serveMeal(int customerId, const std::vector<int>& ingredients);
    void run();

private:

    Cook* cook;
    Chief* chief;
    std::mutex mtx;
    std::vector<std::pair<int, std::vector<int>>> orders;
};

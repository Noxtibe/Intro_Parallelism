#pragma once
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

class Customer;
class Cook;
class Chief;

class Waiter 
{
public:

    Waiter(Cook* cook, Chief* chief);
    void run();
    void placeOrder(int customerId, const std::vector<int>& ingredients);
    void serveMeal(int customerId, const std::vector<int>& ingredients);

private:

    Cook* cook;
    Chief* chief;
    std::queue<std::pair<int, std::vector<int>>> orders;
    std::mutex mtx;
    std::condition_variable cv;
};


#pragma once
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

class Waiter;
class Chief;

class Cook 
{
public:

    Cook(Chief* chief);
    void run();
    void ingredientPreparation(const std::vector<int>& ingredients);

private:

    Waiter* waiter;
    Chief* chief;
    std::queue<std::vector<int>> preparationQueue;
    std::mutex mtx;
    std::condition_variable cv;
};

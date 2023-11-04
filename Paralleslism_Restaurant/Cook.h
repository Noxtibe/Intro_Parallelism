#pragma once

#include <vector>
#include <mutex>

class Waiter;
class Chief;

class Cook 
{
public:

    Cook(Waiter* waiter, Chief* chief);
    void prepareIngredients(const std::vector<int>& ingredients);
    void run();

private:

    Waiter* waiter;
    Chief* chief;
};

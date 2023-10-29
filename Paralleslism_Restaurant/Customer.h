#pragma once
#include <vector>

class Waiter;
class Chief;

class Customer 
{
public:

    Customer(int id, Waiter* waiter, Chief* chief);
    void run();

private:

    int id;
    Waiter* waiter;
    Chief* chief;
};

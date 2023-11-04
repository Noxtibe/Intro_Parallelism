#pragma once

class Waiter;
class Cook;
class Chief;

class Customer 
{
public:

    Customer(int id, Waiter* waiter, Chief* chief);
    void dine();

private:

    int id;
    Waiter* waiter;
    Cook* cook;
    Chief* chief;

};

#include "Customer.h"
#include "Waiter.h"
#include "Cook.h"
#include "Chief.h"
#include <thread>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() 
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Waiter waiter(nullptr, nullptr);
    Cook cook(&waiter, nullptr);
    Chief chief(&cook);

    Customer customer(1, &waiter, &chief);
    customer.dine();



    return 0;
}

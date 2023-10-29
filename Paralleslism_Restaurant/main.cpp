#include "Customer.h"
#include "Waiter.h"
#include "Cook.h"
#include "Chief.h"
#include <vector>

using namespace std;

int main() 
{
    Chief chief(nullptr);
    Cook cook(&chief);
    Waiter waiter(&cook, &chief);


    vector<Customer> customers;
    for (int i = 1; i <= 5; ++i) 
    {
        customers.emplace_back(i, &waiter, &chief);
    }

    vector<thread> threads;
    threads.emplace_back(&Cook::run, &cook);
    threads.emplace_back(&Waiter::run, &waiter);
    for (Customer& customer : customers) {
        threads.emplace_back(&Customer::run, &customer);
    }

    for (thread& thread : threads) 
    {
        thread.join();
    }

    return 0;
}

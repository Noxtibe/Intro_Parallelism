#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
const int limit = 1000;

void printEvenNumbers(int id, int step) 
{
    for (int i = 0; i <= limit; i += 2) 
    {
        // std::lock_guard is used to lock and unlock the mutex automatically, 
        // ensuring that the mutex is released even if an exception is thrown
        lock_guard<mutex> lock(mtx);
        cout << "Thread " << id << " : " << i << endl;
    }
}

int main() 
{
    thread thread1(printEvenNumbers, 1, 2);
    thread thread2(printEvenNumbers, 2, 2);

    thread1.join();
    thread2.join();

    return 0;
}

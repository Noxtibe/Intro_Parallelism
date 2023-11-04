#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
const int limit = 1000;
condition_variable cv;
bool thread1_done = false;

void printEvenNumbers(int id, int step)
{
    for (int i = 0; i <= limit; i += 1)
    {
        if (id == 2)
        {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [] { return thread1_done; });
        }

        lock_guard<mutex> lock(mtx);
        cout << "Thread " << id << " : " << i << endl;
    }

    // Indiquer que le thread 1 a terminé
    if (id == 1)
    {
        unique_lock<mutex> ulock(mtx);
        thread1_done = true;
        ulock.unlock();
        cv.notify_all();
    }
}

int main()
{
    thread thread1(printEvenNumbers, 1, 2);

    // Attendre que le thread 1 termine
    thread1.join();

    // Maintenant, lancer le thread 2
    thread thread2(printEvenNumbers, 2, 2);

    // Attendre que le thread 2 se termine
    thread2.join();

    return 0;
}

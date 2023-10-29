#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

const int n = 100000; // Number of elements in the table
const int m = 4;      // Number of threads

vector<int> table(n);
int global_sum = 0;
std::mutex mutex;

void fillTable() 
{
    for (int i = 0; i < n; ++i) 
    {
        table[i] = i + 1;
    }
}

// Sequential version
int sequentialSum() 
{
    int sum = 0;
    for (int i = 0; i < n; ++i) 
    {
        sum += table[i];
    }
    return sum;
}

// Thread-local variable version
int threadLocalSum(int thread_id) 
{
    int local_sum = 0;
    for (int i = thread_id; i < n; i += m) 
    {
        local_sum += table[i];
    }
    return local_sum;
}

// Global sum variable with mutexes version
void globalSumWithMutex(int thread_id) 
{
    int local_sum = 0;
    for (int i = thread_id; i < n; i += m) 
    {
        local_sum += table[i];
    }
    lock_guard<std::mutex> lock(std::mutex);
    global_sum += local_sum;
}

int main() 
{
    fillTable();

    // Sequential version
    int seq_sum = sequentialSum();
    cout << "Sequential Sum : " << seq_sum << endl;

    // Thread-local variable version
    vector<thread> threads;
    vector<int> thread_sums(m);

    for (int i = 0; i < m; ++i) 
    {
        threads.emplace_back([i, &thread_sums]() 
            {
            thread_sums[i] = threadLocalSum(i);
            });
    }

    for (auto& thread : threads) 
    {
        thread.join();
    }

    int thread_local_sum = 0;
    for (int sum : thread_sums) 
    {
        thread_local_sum += sum;
    }
    cout << "Thread-Local Sum : " << thread_local_sum << endl;

    // Global sum variable with mutexes version
    threads.clear();
    global_sum = 0;

    for (int i = 0; i < m; ++i) 
    {
        threads.emplace_back([i]() 
        {
            globalSumWithMutex(i);
        });
    }

    for (auto& thread : threads) 
    {
        thread.join();
    }

    cout << "Global Sum (Mutex) : " << global_sum << endl;

    return 0;
}

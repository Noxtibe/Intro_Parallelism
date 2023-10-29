#include <iostream>
#include <thread>

using namespace std;

void displayHelloWorld() 
{
    cout << "Hello World !" << endl;
}

void displayGoodByeWorld()
{
    cout << "Goodbye World !" << endl;
}

int main() 
{
    // Create two threads

    thread thread1(displayHelloWorld);
    thread thread2(displayGoodByeWorld);

    // Wait for both threads to finish

    thread1.join();
    thread2.join();

    return 0;
}

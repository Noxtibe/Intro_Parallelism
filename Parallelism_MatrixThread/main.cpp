#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// THREAD VERSION

// Function to multiply two matrices
void multiplyElement(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result, int i, int j)
{
    int A_cols = A[0].size();
    int sum = 0;
    for (int k = 0; k < A_cols; k++)
    {
        sum += A[i][k] * B[k][j];
    }
    result[i][j] = sum;
}

int main()
{
    cout << "Thread Matrix : " << endl;

    // Define matrices A and B
    vector<vector<int>> A = { {1, 2}, {3, 4} };
    vector<vector<int>> B = { {5, 6}, {7, 8} };

    int A_rows = A.size();
    int B_cols = B[0].size();
    vector<vector<int>> result(A_rows, vector<int>(B_cols, 0));

    // Create threads to compute each element of the result matrix
    vector<thread> threads;
    for (int i = 0; i < A_rows; i++)
    {
        for (int j = 0; j < B_cols; j++)
        {
            threads.emplace_back(multiplyElement, ref(A), ref(B), ref(result), i, j);
        }
    }

    for (thread& t : threads)
    {
        t.join();
    }

    for (const auto& row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// SEQUENTIAL VERSION

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) 
{
    int A_rows = A.size();
    int A_cols = A[0].size();
    int B_cols = B[0].size();

    vector<vector<int>> result(A_rows, vector<int>(B_cols, 0));

    for (int i = 0; i < A_rows; i++) 
    {
        for (int j = 0; j < B_cols; j++) 
        {
            for (int k = 0; k < A_cols; k++) 
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() 
{
    cout << "Sequential Matrix : " << endl;

    // Define matrices A and B
    vector<vector<int>> A = { {1, 2}, {3, 4} };
    vector<vector<int>> B = { {5, 6}, {7, 8} };

    // Multiply matrices A and B
    vector<vector<int>> result = multiplyMatrices(A, B);

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



#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    // Check if matrices can be multiplied
    if (colsA != rowsB) {
        cout << "Matrices cannot be multiplied. Invalid dimensions." << endl;
        return {};
    }

    // Result matrix
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrices
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};

    // Multiply matrices
    vector<vector<int>> result = matrixMultiply(A, B);

    // Display result
    cout << "Result of matrix multiplication:" << endl;
    displayMatrix(result);

    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void gaussianElimination(double matrix[][11], int n) {
    for (int i = 0; i < n-1; i++) {
        if(matrix[i][i] == 0) {
            // Handle division by zero
            cout << "Division by zero encountered. Exiting..." << endl;
            return;
        }
        for (int j = i+1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n+1; k++) {
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
            }
        }
    }

    for (int i = n-1; i >= 0; i--) {
        if(matrix[i][i] == 0) {
            // Handle division by zero
            cout << "Division by zero encountered. Exiting..." << endl;
            return; 
        }
        for (int j = i-1; j >= 0; j--) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n+1; k++) {
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
            }
        }
}
}

int main() {
    // Example matrix
    cout << "Enter the number of unknowns: ";
    int n;
    cin >> n;
    double matrix[n][11]; // Assuming maximum size of matrix is 10x10

    cout << "Enter the matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n+1; j++) {
            cin >> matrix[i][j];
        }
    }
    
    gaussianElimination(matrix, n);

    // Print the reduced matrix
    cout << "Reduced matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+1; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Back substitution to find solutions
    cout << "Solution:\n";
    vector<double> solutions(n);
    for (int i = n - 1; i >= 0; i--) {
        solutions[i] = matrix[i][n] / matrix[i][i];
        for (int j = i - 1; j >= 0; j--) {
            matrix[j][n] -= matrix[j][i] * solutions[i];
        }
    }

    // Print the solutions
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solutions[i] << endl;
    }

    return 0;
}

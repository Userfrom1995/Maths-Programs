#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<double> gaussSeidel(const vector<vector<double>>& A, int maxIterations, double tolerance) {
    int n = A.size();
    vector<double> x(n, 0.0);
    vector<double> x_old(n);

    for (int iter = 0; iter < maxIterations; ++iter) {
        x_old = x;
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n+1; ++j) {
                if (j != i)
                 sum -= A[i][j] * x[j];
            }
            x[i] = sum / A[i][i];
        }

        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += abs(x[i] - x_old[i]);
        }

        if (error < tolerance)
            break;
    }

    return x;
}

int main() {
    // Example system of linear equations
    vector<vector<double>> A = {
        {4, -1, 0, 0},
        {-1, 4, -1, 0},
        {0, -1, 4, -1},
        {0, 0, -1, 3}
    };
    vector<double> b = {15, 10, 10, 10};

    vector<double> x = gaussSeidel(A, 1000, 1e-6);

    // Print the solution
    for (double xi : x) {
        cout << xi << " ";
    }
    cout << endl;

    return 0;
}
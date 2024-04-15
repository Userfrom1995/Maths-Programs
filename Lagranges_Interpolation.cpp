#include<iostream>
using namespace std;

double lagrangeInterpolation(double x[], double y[], int n, double xp) {
    double result = 0; // Initialize result

    // Compute Lagrange Interpolation
    for (int i=0; i<n; i++) {
        double term = y[i];
        for (int j=0;j<n;j++) {
            if (j!=i)
                term = term*(xp - x[j])/(x[i] - x[j]);
        }

        // Add current term to result
        result += term;
    }

    return result;
}

int main() {
    cout << "Enter the number of data points: " << endl;
    int n ;
    cin >> n;
    double x[n] ;
    double y[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of x" << i + 1 << ": " << endl;
        cin >> x[i];
       
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of y" << i + 1 << ": " << endl;
        cin >> y[i];
    }
     
    // Value to interpolate at
    cout << "Enter the value of x for which you want to find y: " << endl;
    double xp ;
    cin >> xp;

    cout << "The value of f(" << xp << ") is " << lagrangeInterpolation(x, y, n, xp) << endl;
    return 0;
}
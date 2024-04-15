#include <iostream>
#include <cmath>
#include <functional>

using namespace std;
// The function for which we are finding the root.
double f(double x) {
    // Replace with your actual function.
    return x * x * x - x * x + 2;
}

// False Position Method to find the root of a function f.
double falsePositionMethod( double lower, double upper, double tolerance) {
    if (f(lower) * f(upper) >= 0) {
        cerr << "Incorrect initial lower and upper guesses." << endl;
    
        return NAN; // Not a number (NaN), since there might not be a root.
    }

    double root = lower; // Initial root guess.
   
   while(abs(upper-lower) > tolerance) {
        // Calculate the false position
        root = (lower * f(upper) - upper * f(lower)) / (f(upper) - f(lower));

        // Check the value of f(root)
        double f_root = f(root);

        if (f_root == 0.0 || abs(f_root) < tolerance) {
            // The root has been found or is within tolerance
            return root;
        } else if (f(lower) * f_root < 0) {
            // The root lies between lower and root
            upper = root;
        } else {
            // The root lies between root and upper
            lower = root;
        }
    }

    cerr << "Max iterations reached without convergence." << endl;
    return root; // This might be an approximation of the root.
}

int main() {
   cout<< "Enter the value of lower: ";
    double lower;
    cin >> lower;
    cout << "Enter the value of upper: ";
    double upper;
    cin >> upper;
    cout << "Enter the value of tolerance: ";
    double tolerance;
    cin >> tolerance;

    // int maxIterations = 1000000000000;  // Maximum number of iterations

    double root = falsePositionMethod(lower, upper, tolerance);

    if (!isnan(root)) {
        cout << "Root found: " << root << endl;
    }

    return 0;
}
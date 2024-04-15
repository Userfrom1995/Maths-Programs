#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

// Define a type for a function taking a double and returning a double
 double f(double x) {
     return x*x*x - x*x + 2;
 };

double bisectionMethod( double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        std::cerr << "You have not assumed right a and b\n";
        return -1;
    }

    double c = a;
    while (std ::abs(b - a) >= tolerance) {
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (f(c) == 0.0 || std::abs(f(c)) < tolerance)
            break;

        // Decide the side to repeat the steps
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    // Example function: f(x) = x^3 - x^2 + 2
  

   cout << "Enter the value of a: ";
    double a;
    cin >> a;
    cout << "Enter the value of b: ";
    double b;
    cin >> b;
    cout << "Enter the value of tolerance: ";
    double tolerance;   
    cin >> tolerance;


    double root = bisectionMethod( a, b, tolerance);

    std::cout << "The root is: " << root << std::endl;

    return 0;
}
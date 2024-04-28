#include <iostream>

using namespace std;

// Function defining the ordinary differential equation (ODE) dy/dx = f(x, y)
double f(double x, double y) {
    return x * y; // Example ODE: dy/dx = x * y
}

// Function to perform Modified Euler's Method to solve the ODE
void modified_euler_method(double (*f)(double, double), double x0, double y0, double h, double x_values[], double y_values[], int n) {
    x_values[0] = x0;
    y_values[0] = y0;

    for (int i = 0; i < n; ++i) {
        double x = x_values[i];
        double y = y_values[i];

        // Predictor step using Euler's method
        double y_predictor = y + h * f(x, y);

        // Corrector step
        double x_next = x + h;
        double y_corrector = y + h / 2 * (f(x, y) + f(x_next, y_predictor));

        // Assign values to arrays
        x_values[i + 1] = x_next;
        y_values[i + 1] = y_corrector;
    }
}

int main() {
    double x0 = 0; // Initial value of x
    double y0 = 1; // Initial value of y at x0
    double h = 0.1; // Step size
    int n = 10; // Number of steps

    double x_values[n + 1]; // Array to store x values
    double y_values[n + 1]; // Array to store y values

    modified_euler_method(f, x0, y0, h, x_values, y_values, n);

    cout << "x values:" << endl;
    for (int i = 0; i <= n; ++i) {
        cout << x_values[i] << " ";
    }
    cout << endl;

    cout << "y values:" << endl;
    for (int i = 0; i <= n; ++i) {
        cout << y_values[i] << " ";
    }
    cout << endl;

    return 0;
}

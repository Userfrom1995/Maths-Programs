#include <iostream>

using namespace std;

// Function defining the ordinary differential equation (ODE) dy/dx = f(x, y)
double f(double x, double y) {
    return x * y; // Example ODE: dy/dx = x * y
}

// Function to perform RK4 method to solve the ODE
void runge_kutta_4(double (*f)(double, double), double x0, double y0, double h, double x_values[], double y_values[], int n) {
    x_values[0] = x0;
    y_values[0] = y0;

    for (int i = 0; i < n; ++i) {
        double x = x_values[i];
        double y = y_values[i];

        // Compute k1, k2, k3, and k4
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        // Update y using weighted average of slopes
        y_values[i + 1] = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        // Update x
        x_values[i + 1] = x + h;
    }
}

int main() {
    double x0 = 0; // Initial value of x
    double y0 = 1; // Initial value of y at x0
    double h = 0.1; // Step size
    int n = 10; // Number of steps

    double x_values[n + 1]; // Array to store x values
    double y_values[n + 1]; // Array to store y values

    runge_kutta_4(f, x0, y0, h, x_values, y_values, n);

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

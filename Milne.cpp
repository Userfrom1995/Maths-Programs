#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function defining the ordinary differential equation (ODE) dy/dx = f(x, y)
double f(double x, double y) {
    return x * y; // Example ODE: dy/dx = x * y
}

// Function to perform Milne Predictor-Corrector method to solve the ODE
void milne_predictor_corrector(double (*f)(double, double), double x0, double y0, double h, double x_values[], double y_values[], int n) {
    // Initializing the predictor method using the Runge-Kutta method
    double k1, k2, k3, k4;
    for (int i = 0; i < 4; ++i) {
        k1 = h * f(x0 + i * h, y0);
        k2 = h * f(x0 + i * h + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + i * h + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + i * h + h, y0 + k3);
        y_values[i + 1] = y_values[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x_values[i + 1] = x0 + (i + 1) * h;
    }

    // Performing the corrector method
    for (int i = 3; i < n; ++i) {
        x_values[i + 1] = x_values[i] + h;
        double predictor = y_values[i - 3] + 4 * h / 3 * (2 * f(x_values[i], y_values[i]) - f(x_values[i - 1], y_values[i - 1]) + 2 * f(x_values[i - 2], y_values[i - 2]));
        y_values[i + 1] = y_values[i - 1] + h / 3 * (f(x_values[i - 1], y_values[i - 1]) + 4 * f(x_values[i], y_values[i]) + f(x_values[i + 1], predictor));
    }
}

int main() {
    double x0 = 0; // Initial value of x
    double y0 = 1; // Initial value of y at x0
    double h = 0.1; // Step size
    int n = 10; // Number of steps

    double x_values[n + 1]; // Array to store x values
    double y_values[n + 1]; // Array to store y values

    x_values[0] = x0;
    y_values[0] = y0;

    milne_predictor_corrector(f, x0, y0, h, x_values, y_values, n);

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

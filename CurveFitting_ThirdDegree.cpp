#include <iostream>
#include <vector>
#include <cmath>

// Function to perform curve fitting for a 3rd-degree polynomial
void curveFitting(const std::vector<double>& x, const std::vector<double>& y, double& a, double& b, double& c, double& d) {
    // Number of data points
    int n = x.size();

    // Initialize sums
    double sum_x = 0.0, sum_x2 = 0.0, sum_x3 = 0.0, sum_x4 = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2y = 0.0;

    // Calculate sums
    for (int i = 0; i < n; ++i) {
        double xi = x[i];
        double yi = y[i];
        sum_x += xi;
        sum_x2 += xi * xi;
        sum_x3 += xi * xi * xi;
        sum_x4 += xi * xi * xi * xi;
        sum_y += yi;
        sum_xy += xi * yi;
        sum_x2y += xi * xi * yi;
    }

    // Solve the linear system of equations
    double denominator = n * sum_x2 * sum_x4 - sum_x2 * sum_x2 * sum_x2 - n * sum_x3 * sum_x3 +
                         2 * sum_x * sum_x2 * sum_x3 - sum_x * sum_x * sum_x4;

    a = (sum_y * sum_x2 * sum_x4 - sum_y * sum_x2 * sum_x2 * sum_x2 - sum_xy * sum_x3 * sum_x3 +
         sum_xy * sum_x * sum_x2 * sum_x3 - sum_x2y * sum_x * sum_x * sum_x4) /
        denominator;

    b = (n * sum_x2y * sum_x4 - sum_xy * sum_x2 * sum_x2 * sum_x2 - sum_y * sum_x3 * sum_x3 +
         sum_y * sum_x * sum_x2 * sum_x3 - n * sum_x * sum_x2 * sum_x2y) /
        denominator;

    c = (n * sum_xy * sum_x4 - sum_y * sum_x2 * sum_x2 * sum_x2 - sum_x2y * sum_x3 * sum_x3 +
         sum_x * sum_x2y * sum_x * sum_x3 - sum_y * sum_x * sum_x2 * sum_x4) /
        denominator;

    d = (n * sum_x2 * sum_x2y - sum_x * sum_xy * sum_x2 * sum_x2 + sum_x * sum_x * sum_xy * sum_x2 -
         n * sum_x2 * sum_x * sum_y + sum_x2 * sum_x * sum_y * sum_x) /
        denominator;
}

int main() {
    // Sample data points
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> y = {2.0, 3.0, 5.0, 7.0, 11.0};

    // Coefficients of the fitted polynomial
    double a, b, c, d;
    curveFitting(x, y, a, b, c, d);

    // Output the coefficients
    std::cout << "Fitted polynomial: y = " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << std::endl;

    return 0;
}

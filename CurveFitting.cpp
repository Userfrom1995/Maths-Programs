#include <iostream>
#include <vector>
#include <cmath>

std::pair<double, double> linearCurveFitting(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double a = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double b = (sum_y - a * sum_x) / n;

    return {a, b};
}

std::vector<double> parabolicCurveFitting(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    double x_sum = 0, y_sum = 0, x2_sum = 0, x3_sum = 0, x4_sum = 0, xy_sum = 0, x2y_sum = 0;

    for (int i = 0; i < n; i++) {
        x_sum += x[i];
        y_sum += y[i];
        x2_sum += std::pow(x[i], 2);
        x3_sum += std::pow(x[i], 3);
        x4_sum += std::pow(x[i], 4);
        xy_sum += x[i] * y[i];
        x2y_sum += std::pow(x[i], 2) * y[i];
    }

    // Solve the system of linear equations
    double a = (x2y_sum*(x2_sum*n - x_sum*x_sum) - xy_sum*(x3_sum*n - x_sum*x2_sum) + y_sum*(x3_sum*x_sum - x2_sum*x2_sum)) / 
               (x4_sum*(x2_sum*n - x_sum*x_sum) - x3_sum*(x3_sum*n - x_sum*x2_sum) + x2_sum*(x3_sum*x_sum - x2_sum*x2_sum));

    double b = (x4_sum*(xy_sum*n - y_sum*x_sum) - x3_sum*(x2y_sum*n - y_sum*x2_sum) + x2_sum*(x2y_sum*x_sum - xy_sum*x2_sum)) / 
               (x4_sum*(x2_sum*n - x_sum*x_sum) - x3_sum*(x3_sum*n - x_sum*x2_sum) + x2_sum*(x3_sum*x_sum - x2_sum*x2_sum));

    double c = (x4_sum*(x2_sum*y_sum - x_sum*xy_sum) - x3_sum*(x3_sum*y_sum - x_sum*x2y_sum) + x2_sum*(x3_sum*xy_sum - x2_sum*x2y_sum)) / 
               (x4_sum*(x2_sum*n - x_sum*x_sum) - x3_sum*(x3_sum*n - x_sum*x2_sum) + x2_sum*(x3_sum*x_sum - x2_sum*x2_sum));

    return {a, b, c};
}


int main() {
    // Example data for linear curve fitting
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 3, 5, 7, 11};

    auto result_linear = linearCurveFitting(x, y);
    double a = result_linear.first;
    double b = result_linear.second;

    std::cout << "The best fit line is y = " << a << "x + " << b << std::endl;

    // Example data for parabolic curve fitting
    std::vector<double> s = {1, 2, 3, 4, 5};
    std::vector<double> u = {2, 5, 10, 17, 26};

    std::vector<double> result_parabolic = parabolicCurveFitting(s, u);
    double z = result_parabolic[0];
    double d = result_parabolic[1];
    double h = result_parabolic[2];

    std::cout << "The best fit curve is y = " << z << "x^2 + " << d << "x + " << h << std::endl;

    return 0;
}

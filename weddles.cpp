#include <iostream>
using namespace std;

double func(double x) {
    return (1 / (5 + 4*x));
}

int main() {
    int interval_limit = 6;
    double lower_limit = 0;
    double upper_limit = 5;
    double h = (upper_limit - lower_limit) / interval_limit;
    int n = interval_limit + 1; // Adding 1 to include both limits
    double x[n] = {0};
    double fx[n];
    for (int i = 0; i <= interval_limit; i++) {
        x[i] = lower_limit + i * h;
        fx[i] = func(x[i]);
    }
    double k = 3*h/10;

    double sum = 0; // Initialize sum to 0

    for(int i = 0 ; i <= interval_limit - 6 ; i = i = i + 6){
        sum = sum +k*(fx[i] + 5*fx[i+1] + fx[i+2] + 6*fx[i+3] + fx[i+4] + 5*fx[i+5] + fx[i+6]);
    
    }
    cout << sum;

return 0;
}
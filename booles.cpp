#include <iostream>
using namespace std;

double func(double x) {
    return (1 / (1 + x*x));
}

int main() {
    int interval_limit = 4;
    double lower_limit = 0.2;
    double upper_limit = 0.6;
    double h = (upper_limit - lower_limit) / interval_limit;
    int n = interval_limit + 1; // Adding 1 to include both limits
    double x[n];
    double fx[n];
    for (int i = 0; i <= interval_limit; i++) {
        x[i] = lower_limit + i * h;
        fx[i] = func(x[i]);
    }
    double k = 2*h/45;

    double sum = k*7*(fx[0] + fx[interval_limit]); // Initialize sum to 0



   for (int i = 0; i <= interval_limit - 1; i++)
   {

    if (i % 4 == 0){
        sum = sum + 14*(fx[i])*k;
    }

    else if (i % 4 == 1 || i % 4 == 3){
        sum = sum + 32*(fx[i])*k;
    }

    else if (i % 4 == 2){
        sum = sum + 12*(2*h*fx[i])*k;
    }

    
   }


    cout << sum;

    return 0;
}

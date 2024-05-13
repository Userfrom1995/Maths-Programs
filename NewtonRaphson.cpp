#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
   
    return x * x - 25;
}

double derivFunc(double x) {
   
    return 2 * x;
}

void newtonRaphson(double x, double tolerence) {
    double h = func(x) / derivFunc(x);
    while (abs(h) > tolerence) {
        h = func(x) / derivFunc(x);
        x = x - h;
    }

    cout << "The root is: " << x << endl;
}

int main() {
    cout << "Enter the initial guess: ";
    double initial_guess;
    cin >> initial_guess;

    cout << "Enter the tolerence: ";
    double tolerence;
    cin >> tolerence;


    newtonRaphson(initial_guess, tolerence);
    return 0;
}
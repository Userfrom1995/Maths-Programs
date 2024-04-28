#include <iostream>
#include <cmath>

using namespace std;

// Function to compute sum of sine series
long double sineSeries(long double x, int terms) {
    long double sum = 0;
    for (int n = 0; n < terms; ++n) {
        sum += powl(-1, n) * powl(x, 2 * n + 1) / tgamma(2 * n + 2);
    }
    return sum;
}

// Function to compute sum of cosine series
long double cosineSeries(long double x, int terms) {
    long double sum = 0;
    for (int n = 0; n < terms; ++n) {
        sum += powl(-1, n) * powl(x, 2 * n) / tgamma(2 * n + 1);
    }
    return sum;
}

int main() {
    long double x;
    int terms;

    cout << "Enter the value of x (in radians): ";
    cin >> x;

    cout << "Enter the number of terms: ";
    cin >> terms;

    long double sineSum = sineSeries(x, terms);
    long double cosineSum = cosineSeries(x, terms);

    cout << "Sum of sine series up to " << terms << " terms: " << sineSum << endl;
    cout << "Sum of cosine series up to " << terms << " terms: " << cosineSum << endl;

    return 0;
}

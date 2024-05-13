#include <stdio.h>

#define N 4 // Number of data points

float gaussBackwardInterpolation(float x, float X[N], float Y[N]);

int main() {
    // Given data points
    float X[N] = {10, 15, 20, 25};
    float Y[N] = {227.04, 362.78, 517.35, 718.56};

    // Point at which interpolation is to be done
    float x = 17.5;

    // Interpolate the value at x
    float interpolatedValue = gaussBackwardInterpolation(x, X, Y);

    printf("Interpolated value at x = %.2f is %.2f\n", x, interpolatedValue);

    return 0;
}

float gaussBackwardInterpolation(float x, float X[N], float Y[N]) {
    float h = X[1] - X[0]; // Step size
    float p = (x - X[N-1]) / h;

    float Ytable[N][N]; // Table to store backward differences
    int i, j;

    // Initialize the first column of the table with given Y values
    for (i = 0; i < N; i++) {
        Ytable[i][0] = Y[i];
    }

    // Calculate backward differences
    for (j = 1; j < N; j++) {
        for (i = N - 1; i >= j; i--) {
            Ytable[i][j] = Ytable[i][j-1] - Ytable[i-1][j-1];
        }
    }

    float result = Y[N-1]; // Interpolated value

    float u = 1;
    for (i = 1; i < N; i++) {
        u *= (p + i - 1) / i;
        result += u * Ytable[N-1][i];
    }

    return result;
}
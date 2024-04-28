#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    // Initialize position for 1
    int i = 0;
    int j = n / 2;

    // One by one put all values in magic square
    for (int num = 1; num <= n * n; ++num) {
        magicSquare[i][j] = num;

        // Calculate next position
        int nexti = (i - 1 + n) % n;
        int nextj = (j + 1) % n;

        // If the next position is already filled or out of bounds, move down
        if (magicSquare[nexti][nextj] != 0) {
            i = (i + 1) % n;
        } else {
            i = nexti;
            j = nextj;
        }
    }

    return magicSquare;
}

void printMagicSquare(const vector<vector<int>>& magicSquare) {
    for (const auto& row : magicSquare) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the magic square (N x N): ";
    cin >> n;

    if (n % 2 == 0 && n < 4) {
        cout << "Magic square is not possible for even numbers less than 4x4 size." << endl;
        return 1;
    }

    vector<vector<int>> magicSquare = generateMagicSquare(n);

    cout << "The Magic Square of size " << n << " x " << n << " is:" << endl;
    printMagicSquare(magicSquare);

    return 0;
}

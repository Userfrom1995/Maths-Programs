#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    // Initialize position for 1
    int i = n / 2;
    int j = n - 1;

    // One by one put all values in magic square
    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            // Wrap around row
            if (j == n)
                j = 0;
            // Wrap around column
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else
            magicSquare[i][j] = num++;

        j++;
        i--;
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

    if (n < 3) {
        cout << "Magic square is not possible for less than 3x3 size." << endl;
        return 1;
    }

    vector<vector<int>> magicSquare = generateMagicSquare(n);

    cout << "The Magic Square of size " << n << " x " << n << " is:" << endl;
    printMagicSquare(magicSquare);

    return 0;
}

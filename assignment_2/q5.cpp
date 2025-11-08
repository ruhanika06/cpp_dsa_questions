#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    // (a) Diagonal Matrix
    cout << "\n(a) Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << mat[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    // (b) Tri-diagonal Matrix
    cout << "\n(b) Tri-diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) <= 1) // main + upper + lower diagonal
                cout << mat[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    // (c) Lower Triangular Matrix
    cout << "\n(c) Lower Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << mat[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    // (d) Upper Triangular Matrix
    cout << "\n(d) Upper Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << mat[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    // (e) Symmetric Matrix (check + display)
    bool symmetric = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                symmetric = false;
                break;
            }
        }
        if (!symmetric) break;
    }

    cout << "\n(e) Symmetric Matrix:\n";
    if (symmetric) {
        cout << "The given matrix is Symmetric.\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "The given matrix is NOT Symmetric.\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int a[10][10], r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++)
            rowSum += a[i][j];
        cout << "Sum of row " << i + 1 << " = " << rowSum << endl;
    }

    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++)
            colSum += a[i][j];
        cout << "Sum of column " << j + 1 << " = " << colSum << endl;
    }
    return 0;
}

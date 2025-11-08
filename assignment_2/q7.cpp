#include <iostream>
using namespace std;

int countInversions(int arr[], int n) {
    int cnt = 0;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j]) cnt++;
    return cnt;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Inversion count: " << countInversions(arr, n);
}

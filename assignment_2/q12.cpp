#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        switch (arr[mid]) {
            case 0: swap(arr[low++], arr[mid++]); break;
            case 1: mid++; break;
            case 2: swap(arr[mid], arr[high--]); break;
        }
    }
}

int main() {
    int arr[] = {0, 2, 1, 2, 0, 1, 1, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);
    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}

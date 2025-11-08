#include <iostream>
using namespace std;

// Linear approach
int findMissingLinear(int arr[], int n) {
    int expected = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != expected) return expected;
        expected++;
    }
    return -1;
}

// Binary search approach
int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) low = mid + 1;
        else high = mid - 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing number (Binary): " << findMissingBinary(arr, n) << endl;
    return 0;
}

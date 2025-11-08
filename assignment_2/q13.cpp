#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int possibleDups = 0;
    int last = n - 1;

    // Count the number of 2s that can be duplicated
    for (int i = 0; i <= last - possibleDups; i++) {
        if (arr[i] == 2) {
            // Edge case: this 2 can't be duplicated if it's at boundary
            if (i == last - possibleDups) {
                arr[last] = 2;
                last--;
                break;
            }
            possibleDups++;
        }
    }

    int lastIndex = last - possibleDups;

    // Work backwards duplicating 2s
    for (int i = lastIndex; i >= 0; i--) {
        if (arr[i] == 2) {
            arr[i + possibleDups] = 2;
            possibleDups--;
            arr[i + possibleDups] = 2;
        } else {
            arr[i + possibleDups] = arr[i];
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 2, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    duplicateTwos(arr, n);

    cout << "Array after duplicating 2s: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

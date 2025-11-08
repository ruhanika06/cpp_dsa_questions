#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get maximum value in arr[]
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Counting Sort based on the digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Step 1: Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Step 2: Convert count[i] to actual position (cumulative)
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Step 3: Build the output array (stable sorting)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Step 4: Copy output back to arr
    arr = output;
}

// Main function for Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    // Apply counting sort to each digit place (1s, 10s, 100s...)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Function to display the array
void display(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array: ";
    display(arr);

    radixSort(arr);

    cout << "Sorted Array (Radix Sort): ";
    display(arr);

    return 0;
}

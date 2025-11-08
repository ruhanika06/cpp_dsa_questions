#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Counting Sort
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Step 1: Find the range (min and max)
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    // Step 2: Create a count array
    vector<int> count(range, 0);

    // Step 3: Store the count of each element
    for (int num : arr)
        count[num - minVal]++;

    // Step 4: Modify count array to store cumulative sum
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Step 5: Build the output array
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // Step 6: Copy sorted output back to original array
    arr = output;
}

// Function to display the array
void display(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
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

    countingSort(arr);

    cout << "Sorted Array (Counting Sort): ";
    display(arr);

    return 0;
}

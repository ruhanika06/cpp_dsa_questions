#include <iostream>
#include <vector>
using namespace std;

// Function to display the array
void display(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// Improved Selection Sort
void improvedSelectionSort(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // Find both min and max in the current unsorted section
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum element at correct position (left)
        swap(arr[left], arr[minIndex]);

        // If the max element was swapped to minIndex position,
        // update its index to reflect the change
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum element at correct position (right)
        swap(arr[right], arr[maxIndex]);

        // Move boundaries inward
        left++;
        right--;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nOriginal Array: ";
    display(arr);

    improvedSelectionSort(arr);

    cout << "Sorted Array (Improved Selection Sort): ";
    display(arr);

    return 0;
}

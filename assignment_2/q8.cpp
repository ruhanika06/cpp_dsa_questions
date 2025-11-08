#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {//o(n^2)
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        // Check if arr[i] has appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct) count++;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_set<int> s;  // Declare unordered_set

    // Insert all elements into the set
    for(int i=0; i<n; i++){//better approach -o(n)
        s.insert(arr[i]);  
    }

    cout << "Total distinct elements: " << s.size() << endl;

    cout << "Total distinct elements = " << countDistinct(arr, n) << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// Function to display array
void display(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Merge Sort Helper Functions
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;

    while (i < L.size() && j < R.size())
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort Helper Functions
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main Menu Function
int main() {
    vector<int> arr;
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;
    arr.resize(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    do {
        cout << "\n------ Sorting Menu ------";
        cout << "\n1. Selection Sort";
        cout << "\n2. Insertion Sort";
        cout << "\n3. Bubble Sort";
        cout << "\n4. Merge Sort";
        cout << "\n5. Quick Sort";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        vector<int> temp = arr; // make a copy to preserve original

        switch (choice) {
            case 1:
                selectionSort(temp);
                cout << "Sorted Array (Selection Sort): ";
                display(temp);
                break;
            case 2:
                insertionSort(temp);
                cout << "Sorted Array (Insertion Sort): ";
                display(temp);
                break;
            case 3:
                bubbleSort(temp);
                cout << "Sorted Array (Bubble Sort): ";
                display(temp);
                break;
            case 4:
                mergeSort(temp, 0, temp.size() - 1);
                cout << "Sorted Array (Merge Sort): ";
                display(temp);
                break;
            case 5:
                quickSort(temp, 0, temp.size() - 1);
                cout << "Sorted Array (Quick Sort): ";
                display(temp);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

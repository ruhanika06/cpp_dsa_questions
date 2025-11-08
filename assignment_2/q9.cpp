#include <iostream>
#include <unordered_set>
using namespace std;

int countPairs(int arr[], int n, int k) {
    unordered_set<int> s(arr, arr+n);
    int count = 0;
    for (int i = 0; i < n; i++)
        if (s.count(arr[i] + k)) count++;
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = 5, k = 2;
    cout << "Pairs with diff " << k << ": " << countPairs(arr, n, k);
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        // Pop elements greater or equal to arr[i]
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If stack not empty, top is nearest smaller
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push current element
        s.push(arr[i]);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = nearestSmallerToLeft(arr);

    cout << "Nearest smaller to left: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
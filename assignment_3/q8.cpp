#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n), nge(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        // Remove smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack empty → no greater element
        if (st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    // Print result
    for (int x : nge)
        cout << x << " ";

    return 0;
}

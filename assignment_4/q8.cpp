#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int>& q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int front = q.front();
        q.pop();

        if (front == expected)
            expected++;
        else {
            while (!st.empty() && st.top() == expected) {
                st.pop();
                expected++;
            }
            if (!st.empty() && st.top() < front)
                return false;
            st.push(front);
        }
    }

    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    return (expected - 1 == n);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    queue<int> q;
    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    if (checkSorted(q))
        cout << "Yes, can be sorted using a stack.\n";
    else
        cout << "No, cannot be sorted using a stack.\n";

    return 0;
}

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool canBeSorted(vector<int>& A) {
    stack<int> S;
    vector<int> B;
    int n = A.size();
    int expected = 1;

    while (!A.empty() || !S.empty()) {
        if (!S.empty() && S.top() == expected) {
            B.push_back(S.top());
            S.pop();
            expected++;
        } 
        else if (!A.empty()) {
            if (A.front() == expected) {
                B.push_back(A.front());
                A.erase(A.begin());
                expected++;
            } else {
                S.push(A.front());
                A.erase(A.begin());
            }
        } 
        else {
            break;
        }
    }

    // Check if B is sorted
    for (int i = 1; i < B.size(); i++) {
        if (B[i] < B[i - 1])
            return false;
    }

    return (B.size() == n);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> A(n);

    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    if (canBeSorted(A))
        cout << "✅ YES, possible to sort array using stack operations.\n";
    else
        cout << "❌ NO, not possible to get sorted array B.\n";

    return 0;
}

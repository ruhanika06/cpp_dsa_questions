#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++)
        cin >> B[i];

    unordered_set<int> setA(A.begin(), A.end());
    vector<int> common;

    for (int x : B) {
        if (setA.count(x)) {
            common.push_back(x);
        }
    }

    for (int x : common)
        cout << x << " ";

    return 0;
}

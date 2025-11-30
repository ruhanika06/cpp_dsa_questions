#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> target;

    unordered_set<int> seen;

    for (int x : arr) {
        int needed = target - x;

        if (seen.count(needed)) {
            cout << "true";
            return 0;
        }

        seen.insert(x);
    }

    cout << "false";
    return 0;
}

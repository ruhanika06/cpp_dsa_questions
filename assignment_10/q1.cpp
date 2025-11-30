#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_set<int> seen;

    for (int x : nums) {
        if (seen.count(x)) {
            cout << "true";
            return 0;
        }
        seen.insert(x);
    }

    cout << "false";
    return 0;
}

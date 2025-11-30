#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_map<int, int> freq;

    // Step 1: Count frequencies
    for (int x : nums) {
        freq[x]++;
    }

    // Step 2: Find first element whose freq = 1
    for (int x : nums) {
        if (freq[x] == 1) {
            cout << x;
            return 0;
        }
    }

    // If no unique element exists
    cout << -1;
}

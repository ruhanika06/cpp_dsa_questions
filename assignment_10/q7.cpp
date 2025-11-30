#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> freq;

    // Count frequencies
    for (int x : arr) {
        freq[x]++;
    }

    int maxFreq = 0;
    int ans = -1;

    for (auto &p : freq) {
        int value = p.first;
        int count = p.second;

        if (count > maxFreq) {
            maxFreq = count;
            ans = value;
        }
        else if (count == maxFreq) {
            ans = max(ans, value); // pick the larger value on tie
        }
    }

    cout << ans;
    return 0;
}

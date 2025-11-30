#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    unordered_map<int, int> freq;

    // Increase count for a[]
    for (int x : a)
        freq[x]++;

    // Decrease count for b[]
    for (int x : b) {
        if (freq.find(x) == freq.end()) {
            cout << "false";
            return 0;
        }
        freq[x]--;
        if (freq[x] < 0) {
            cout << "false";
            return 0;
        }
    }

    // Finally all frequencies must be zero
    for (auto &p : freq) {
        if (p.second != 0) {
            cout << "false";
            return 0;
        }
    }

    cout << "true";
    return 0;
}

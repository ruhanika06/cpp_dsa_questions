#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Function to reverse groups of size k in a doubly linked list
void reverseInGroups(list<int>& dll, int k) {
    if (dll.empty() || k <= 1) return;

    vector<int> temp;  // to temporarily store nodes
    auto it = dll.begin();

    while (it != dll.end()) {
        temp.clear();

        // Take k elements (or less if near end)
        for (int i = 0; i < k && it != dll.end(); i++, it++) {
            temp.push_back(*it);
        }

        // Reverse current group
        reverse(temp.begin(), temp.end());

        // Replace in the list
        for (int val : temp) {
            // move back k positions to overwrite the previous group
            it--;
            *it = val;
        }

        // Move iterator forward again for next group
        for (int i = 0; i < (int)temp.size(); i++) {
            if (it != dll.end()) ++it;
        }
    }
}

int main() {
    list<int> dll;
    int n, k, val;

    cout << "Enter number of elements in Doubly Linked List: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.push_back(val);
    }

    cout << "Enter group size k: ";
    cin >> k;

    cout << "\nOriginal Doubly Linked List:\n";
    for (int x : dll) cout << x << " ";
    cout << endl;

    reverseInGroups(dll, k);

    cout << "\nList after reversing every group of " << k << " nodes:\n";
    for (int x : dll) cout << x << " ";
    cout << endl;

    return 0;
}

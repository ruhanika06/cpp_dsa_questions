#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkDuplicates(Node* root, unordered_set<int> &seen) {
    if (root == NULL) return false;

    // If value already exists in set → duplicate detected
    if (seen.count(root->val)) {
        return true;
    }

    seen.insert(root->val);

    // Check left or right subtree
    return checkDuplicates(root->left, seen) || checkDuplicates(root->right, seen);
}

int main() {
    // Example:
    //       5
    //     /   \
    //    3     7
    //         / \
    //        3   9   ← duplicate (3)

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    unordered_set<int> seen;

    if (checkDuplicates(root, seen))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}

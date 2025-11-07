#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to find maximum depth of binary tree
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main() {
    /* Constructing the following binary tree:
              1
             / \
            2   3
           / \
          4   5

    Maximum Depth = 3 (path: 1 → 2 → 4 or 1 → 2 → 5)
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Maximum Depth of the Binary Tree: " << maxDepth(root) << endl;

    return 0;
}

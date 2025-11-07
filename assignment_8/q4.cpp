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

// Function to check if tree is BST using Inorder traversal
bool isBSTUtil(Node* root, Node* &prev) {
    if (root == NULL)
        return true;

    // Check left subtree
    if (!isBSTUtil(root->left, prev))
        return false;

    // Check current node value > previous value
    if (prev != NULL && root->data <= prev->data)
        return false;

    prev = root; // Update previous node

    // Check right subtree
    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root) {
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}

// Helper to create a tree (for testing)
Node* newNode(int data) {
    return new Node(data);
}

int main() {
    /* Constructing the following tree:
              4
             / \
            2   5
           / \
          1   3
    */
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if (isBST(root))
        cout << "The given tree is a BST" << endl;
    else
        cout << "The given tree is NOT a BST" << endl;

    return 0;
}

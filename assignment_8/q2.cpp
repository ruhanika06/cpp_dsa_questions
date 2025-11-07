#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert a node in BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// (a) Search in BST - Recursive
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);

    return searchRecursive(root->right, key);
}

// (a) Search in BST - Iterative
Node* searchIterative(Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// (b) Maximum element in BST
int findMaximum(Node* root) {
    if (root == NULL)
        return -1; // or handle empty tree case

    while (root->right != NULL)
        root = root->right;
    return root->data;
}

// (c) Minimum element in BST
int findMinimum(Node* root) {
    if (root == NULL)
        return -1;

    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// (d) In-order Successor
Node* inorderSuccessor(Node* root, int key) {
    Node* curr = searchIterative(root, key);
    if (curr == NULL) return NULL;

    // Case 1: Node has right subtree
    if (curr->right != NULL) {
        Node* temp = curr->right;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    // Case 2: No right subtree -> go to ancestors
    Node* successor = NULL;
    Node* ancestor = root;
    while (ancestor != curr) {
        if (key < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

// (e) In-order Predecessor
Node* inorderPredecessor(Node* root, int key) {
    Node* curr = searchIterative(root, key);
    if (curr == NULL) return NULL;

    // Case 1: Has left subtree
    if (curr->left != NULL) {
        Node* temp = curr->left;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }

    // Case 2: No left subtree
    Node* predecessor = NULL;
    Node* ancestor = root;
    while (ancestor != curr) {
        if (key > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

int main() {
    Node* root = NULL;
    int arr[] = { 20, 10, 5, 15, 30, 25, 35 };
    for (int x : arr) {
        root = insert(root, x);
    }

    cout << "Min element: " << findMinimum(root) << endl;
    cout << "Max element: " << findMaximum(root) << endl;

    int key = 10;

    Node* succ = inorderSuccessor(root, key);
    Node* pred = inorderPredecessor(root, key);

    if (succ) cout << "Inorder Successor of " << key << ": " << succ->data << endl;
    else cout << "No Inorder Successor exists for " << key << endl;

    if (pred) cout << "Inorder Predecessor of " << key << ": " << pred->data << endl;
    else cout << "No Inorder Predecessor exists for " << key << endl;

    return 0;
}

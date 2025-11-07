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

// (a) Insert element into BST (No duplicates allowed)
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        cout << "Duplicate value " << key << " not allowed!" << endl;

    return root;
}

// Helper: Find minimum value node in tree
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// (b) Delete an element from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        cout << "Element not found!" << endl;
        return root;
    }

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child (right)
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 3: One child (left)
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 4: Two children
        Node* temp = findMin(root->right); // In-order successor
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// (c) Maximum depth of BST
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

// (d) Minimum depth of BST
int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    // If one subtree is missing, consider the other
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);

    // If both subtrees exist
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Display BST in inorder
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Insert nodes
    int arr[] = { 20, 10, 5, 15, 30, 25, 35 };
    for (int x : arr)
        root = insert(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nDeleting 10..." << endl;
    root = deleteNode(root, 10);

    cout << "Inorder after deletion: ";
    inorder(root);

    cout << "\nMaximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}

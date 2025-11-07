#include <iostream>
#include <unordered_map>
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

// Function to build tree
Node* buildTreeHelper(int preorder[], int inorder[], int start, int end, int &preIndex, unordered_map<int,int> &inMap) {
    if (start > end)
        return NULL;

    // Pick current node as root from preorder
    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    // If leaf node
    if (start == end)
        return root;

    // Find root position in inorder
    int inIndex = inMap[rootVal];

    // Build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, start, inIndex - 1, preIndex, inMap);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, end, preIndex, inMap);

    return root;
}

Node* buildTree(int preorder[], int inorder[], int n) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++)
        inMap[inorder[i]] = i;

    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, n - 1, preIndex, inMap);
}

// Print Inorder to confirm correctness
void printInorder(Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[]  = {9, 3, 15, 20, 7};
    int n = 5;

    Node* root = buildTree(preorder, inorder, n);

    cout << "Tree constructed successfully! Inorder of tree: ";
    printInorder(root);  // Should match the original inorder

    return 0;
}

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

Node* buildTreeHelper(int inorder[], int postorder[], int start, int end, int &postIndex, unordered_map<int,int> &inMap) {
    if (start > end)
        return NULL;

    // Pick current node (root) from postorder
    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

    // If only one node
    if (start == end)
        return root;

    // Find root position in inorder
    int inIndex = inMap[rootVal];

    // IMPORTANT: Build right subtree first, then left
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, end, postIndex, inMap);
    root->left = buildTreeHelper(inorder, postorder, start, inIndex - 1, postIndex, inMap);

    return root;
}

Node* buildTree(int inorder[], int postorder[], int n) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++)
        inMap[inorder[i]] = i;

    int postIndex = n - 1;
    return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex, inMap);
}

// Utility: print inorder to verify
void printInorder(Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int inorder[]    = {9, 3, 15, 20, 7};
    int postorder[]  = {9, 15, 7, 20, 3};
    int n = 5;

    Node* root = buildTree(inorder, postorder, n);

    cout << "Tree constructed successfully! Inorder of tree: ";
    printInorder(root);   // Should match the original inorder

    return 0;
}

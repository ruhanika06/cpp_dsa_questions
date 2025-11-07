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

// Function to check if a node is a leaf
bool isLeaf(Node* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

// Function to return sum of left leaves
int sumOfLeftLeaves(Node* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // If left child is a leaf, add its value
    if (isLeaf(root->left))
        sum += root->left->data;
    else
        // otherwise, recursively process left subtree
        sum += sumOfLeftLeaves(root->left);

    // Always process right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    /* Constructing the following tree:
              3
             / \
            9   20
               /  \
              15   7

    Left leaves = 9 + 15 = 24
    */
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of Left Leaves: " << sumOfLeftLeaves(root) << endl;

    return 0;
}

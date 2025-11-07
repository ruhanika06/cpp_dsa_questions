#include <iostream>
#include <vector>
#include <queue>
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

// Function to get right view of the binary tree
vector<int> rightView(Node* root) {
    vector<int> result;
    if (root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();  // Number of nodes at current level
        
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            // Last node of the level → Right View
            if (i == size - 1)
                result.push_back(current->data);

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
    return result;
}

int main() {
    /* Constructing the following tree:
              1
             / \
            2   3
             \    \
              5    4

    Right View: 1, 3, 4
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    vector<int> view = rightView(root);
    
    cout << "Right View of the Tree: ";
    for (int val : view)
        cout << val << " ";

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Node structure with 4 pointers
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;

    Node(int val) {
        data = val;
        next = prev = up = down = nullptr;
    }
};

// Function to convert a 2D matrix into a 4-pointer doubly linked list
Node* convertToLinkedList(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return nullptr;

    int n = matrix.size();
    int m = matrix[0].size();

    // Create a 2D vector of Node* to store node addresses
    vector<vector<Node*>> nodePtr(n, vector<Node*>(m, nullptr));

    // Step 1: Create all nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nodePtr[i][j] = new Node(matrix[i][j]);
        }
    }

    // Step 2: Connect the nodes in all 4 directions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) nodePtr[i][j]->prev = nodePtr[i][j - 1]; // left
            if (j < m - 1) nodePtr[i][j]->next = nodePtr[i][j + 1]; // right
            if (i > 0) nodePtr[i][j]->up = nodePtr[i - 1][j]; // up
            if (i < n - 1) nodePtr[i][j]->down = nodePtr[i + 1][j]; // down
        }
    }

    // Step 3: Return the head (top-left corner)
    return nodePtr[0][0];
}

// Function to display the linked list row-wise
void displayList(Node* head, int rows, int cols) {
    Node* rowHead = head;
    while (rowHead) {
        Node* curr = rowHead;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
        rowHead = rowHead->down;
    }
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    Node* head = convertToLinkedList(matrix);

    cout << "\nDoubly Linked List (4-directional) representation:\n";
    displayList(head, n, m);

    return 0;
}

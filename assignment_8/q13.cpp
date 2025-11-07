#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;   // will act as previous in DLL
    Node* right;  // will act as next in DLL

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Convert BST to sorted DLL (Inorder traversal)
void bstToDLL(Node* root, Node* &head, Node* &prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (prev == NULL)
        head = root;         // First node becomes head
    else {
        prev->right = root;  // Link previous with current
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

// Merge two sorted DLLs
Node* mergeDLL(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head = NULL;
    Node* tail = NULL;

    while (head1 && head2) {
        Node* temp;
        if (head1->data < head2->data) {
            temp = head1;
            head1 = head1->right;
        } else {
            temp = head2;
            head2 = head2->right;
        }

        if (head == NULL) {
            head = temp;
            head->left = NULL;
            tail = temp;
        } else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }

    // Append remaining elements
    if (head1) tail->right = head1, head1->left = tail;
    if (head2) tail->right = head2, head2->left = tail;

    return head;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    // BST 1
    root1 = insert(root1, 20);
    insert(root1, 10);
    insert(root1, 30);

    // BST 2
    root2 = insert(root2, 25);
    insert(root2, 15);
    insert(root2, 35);

    // Convert both to DLLs
    Node *head1 = NULL, *prev1 = NULL;
    bstToDLL(root1, head1, prev1);

    Node *head2 = NULL, *prev2 = NULL;
    bstToDLL(root2, head2, prev2);

    // Merge both DLLs
    Node* mergedHead = mergeDLL(head1, head2);

    // Print merged DLL
    cout << "Merged Doubly Linked List: ";
    Node* temp = mergedHead;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    return 0;
}

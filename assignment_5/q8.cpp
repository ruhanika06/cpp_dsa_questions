#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to rotate linked list left by k positions
Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0) return head;

    // Step 1: Count the number of nodes
    Node* temp = head;
    int n = 1;
    while (temp->next) {
        temp = temp->next;
        n++;
    }

    // Step 2: Normalize k
    k = k % n;
    if (k == 0) return head;

    // Step 3: Traverse to the k-th node
    Node* current = head;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }

    // Step 4: Break the list and update new head
    Node* new_head = current->next;
    current->next = nullptr;

    // Step 5: Connect the end of new list to old head
    temp->next = head;

    return new_head;
}

// Function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to append a node at the end
void appendNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Main function
int main() {
    Node* head = nullptr;

    // Example list: 1->2->3->4->5->6->7->8->9
    for (int i = 1; i <= 9; i++) {
        appendNode(head, i);
    }

    cout << "Original List: ";
    printList(head);

    int k = 3; // Rotate by 3 positions
    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << " positions: ";
    printList(head);

    return 0;
}

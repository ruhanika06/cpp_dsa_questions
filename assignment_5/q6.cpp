#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to reverse K nodes
Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1)
        return head;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    int count = 0;

    // Step 1: Check if there are at least k nodes
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (!temp) return head; // less than k nodes
        temp = temp->next;
    }

    // Step 2: Reverse k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: Recursively reverse remaining nodes
    if (next != NULL)
        head->next = reverseKGroup(next, k);

    // prev is new head of this segment
    return prev;
}

// Function to display the list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example 1: 1→2→3→4→5→6→7→8→9, K=3
    for (int i = 1; i <= 9; i++)
        insertAtEnd(head, i);

    cout << "Original List: ";
    display(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    display(head);

    return 0;
}

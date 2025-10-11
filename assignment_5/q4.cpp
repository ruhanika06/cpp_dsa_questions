#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert at the end
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

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev one step forward
        curr = next;         // move curr one step forward
    }

    head = prev;  // new head after reversal
}

// Function to display the list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Example: 1->2->3->4->NULL
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    cout << "Original Linked List: ";
    display(head);

    reverseList(head);

    cout << "Reversed Linked List: ";
    display(head);

    return 0;
}

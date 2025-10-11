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

// Function to find middle using slow and fast pointers
int findMiddle(Node* head) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return -1;
    }

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 and slow by 1
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow now points to middle
    return slow->data;
}

// Function to display the list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example input: 1->2->3->4->5
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    cout << "Linked List: ";
    display(head);

    int middle = findMiddle(head);
    cout << "Middle Element: " << middle << endl;

    return 0;
}

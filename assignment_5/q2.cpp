#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert node at end
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

// Function to count and delete all occurrences of key
int deleteOccurrences(Node*& head, int key) {
    int count = 0;

    // Delete nodes from the beginning if they have the key
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Delete from middle or end
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

// Function to display linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    // Example: 1->2->1->2->1->3->1
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 1);

    int key = 1;

    cout << "Original Linked List: ";
    display(head);
    cout << endl;

    int count = deleteOccurrences(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display(head);
    cout << endl;

    return 0;
}

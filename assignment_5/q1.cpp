#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// (a) Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// (b) Insert at end
void insertAtEnd(int value) {
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

// (c) Insert before or after a given value
void insertBeforeAfter(int key, int value, bool before) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        cout << "List is empty!\n";
        delete newNode;
        return;
    }

    // if key is at head and inserting before
    if (before && head->data == key) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Node with value " << key << " not found!\n";
        delete newNode;
        return;
    }

    if (before) {
        prev->next = newNode;
        newNode->next = curr;
    } else {
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// (d) Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// (e) Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// (f) Delete a specific node
void deleteSpecificNode(int key) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Node with value " << key << " not found!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

// (g) Search node and display position
void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node with value " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node with value " << key << " not found!\n";
}

// (h) Display all node values
void displayList() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, key;
    bool beforeAfter;

    while (true) {
        cout << "\n====== Singly Linked List Menu ======\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Insert After a Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cout << "Enter key to insert before: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertBeforeAfter(key, value, true);
                break;

            case 4:
                cout << "Enter key to insert after: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertBeforeAfter(key, value, false);
                break;

            case 5:
                deleteFromBeginning();
                break;

            case 6:
                deleteFromEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteSpecificNode(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 9:
                displayList();
                break;

            case 10:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

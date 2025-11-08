#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void insertEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    // Make list circular (for testing)
    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = head; // last node points to head
    }

    bool isCircular() {
        if (!head) return false;

        Node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;

        return (temp == head);
    }

    void display() {
        Node* temp = head;
        int count = 0; // prevent infinite loop
        cout << "List elements: ";
        while (temp && count < 20) {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    cout << "Initially:\n";
    list.display();
    cout << (list.isCircular() ? "List is Circular.\n" : "List is NOT Circular.\n");

    list.makeCircular();

    cout << "\nAfter making circular:\n";
    cout << (list.isCircular() ? "List is Circular.\n" : "List is NOT Circular.\n");

    return 0;
}

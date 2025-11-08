#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* last;
public:
    CircularLinkedList() { last = nullptr; }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void displayWithRepeat() {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << last->next->data << endl; // repeat head value
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);

    cll.displayWithRepeat();
    return 0;
}

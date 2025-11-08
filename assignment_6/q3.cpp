#include <iostream>
using namespace std;

/* Doubly Linked List */
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void insertEnd(int val) {
        DNode* newNode = new DNode{val, nullptr, nullptr};
        if (!head) head = newNode;
        else {
            DNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    int getSize() {
        int count = 0;
        DNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

/* Circular Linked List */
struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
    CNode* last;
public:
    CircularLinkedList() { last = nullptr; }

    void insertEnd(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    int getSize() {
        if (!last) return 0;
        int count = 0;
        CNode* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);

    cll.insertEnd(5);
    cll.insertEnd(15);
    cll.insertEnd(25);
    cll.insertEnd(35);

    cout << "Size of Doubly Linked List: " << dll.getSize() << endl;
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;

    return 0;
}

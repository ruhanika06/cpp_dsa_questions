#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() { head = nullptr; }

    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    // Split into two halves
    void splitList(CircularLinkedList& firstHalf, CircularLinkedList& secondHalf) {
        if (head == nullptr || head->next == head)
            return;

        Node* slow = head;
        Node* fast = head;

        // Move fast by 2 and slow by 1
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // For even number of nodes, fast->next == head
        // For odd, fast->next->next == head
        if (fast->next->next == head)
            fast = fast->next;

        // Set head of first half
        firstHalf.head = head;

        // Set head of second half
        if (head->next != head)
            secondHalf.head = slow->next;

        // Make the two halves circular
        fast->next = slow->next;  // end of second half
        slow->next = head;        // end of first half
    }

    // Display circular list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList clist, firstHalf, secondHalf;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        clist.insertEnd(val);
    }

    cout << "\nOriginal Circular Linked List:\n";
    clist.display();

    clist.splitList(firstHalf, secondHalf);

    cout << "\nFirst Half:\n";
    firstHalf.display();

    cout << "\nSecond Half:\n";
    secondHalf.display();

    return 0;
}

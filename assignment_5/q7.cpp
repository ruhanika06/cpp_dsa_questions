#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to detect and remove loop
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;
    bool loopExists = false;

    // Detect loop using Floyd's algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    // If loop exists
    if (loopExists) {
        slow = head;

        // Special case: if loop starts at head
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } else {
            // Move both until they meet at start of loop
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Break the loop
        fast->next = NULL;
    }
}

// Helper to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop for testing: connecting last node to node 3
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    cout << "Linked list after removing loop: ";
    printList(head);

    return 0;
}

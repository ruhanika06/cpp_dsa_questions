#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        prev = next = random = nullptr;
    }
};

// Function to print the list and random links
void printList(Node* head) {
    Node* temp = head;
    cout << "\nList (data -> random):\n";
    while (temp) {
        cout << temp->data << " -> ";
        if (temp->random)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}

// Function to correct the random pointer
void fixRandomPointer(Node* head) {
    if (!head) return;

    // Step 1: Store mapping of data → node
    unordered_map<int, Node*> mp;
    Node* temp = head;
    while (temp) {
        mp[temp->data] = temp;
        temp = temp->next;
    }

    // Step 2: Correct random pointers
    temp = head;
    while (temp) {
        if (temp->random && mp.find(temp->data + 1) != mp.end()) {
            // If random doesn’t point to expected (data + 1)
            if (temp->random != mp[temp->data + 1]) {
                temp->random = mp[temp->data + 1];
                cout << "\nFixed random pointer of node " << temp->data << endl;
            }
        }
        temp = temp->next;
    }
}

int main() {
    // Creating a sample doubly linked list: 10 <-> 20 <-> 30 <-> 40
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    // Set random pointers (one wrong)
    n1->random = n2;
    n2->random = n3;
    n3->random = n1; // ❌ wrong (should point to n4)
    n4->random = n1;

    cout << "Before fixing:";
    printList(n1);

    fixRandomPointer(n1);

    cout << "\nAfter fixing:";
    printList(n1);

    return 0;
}

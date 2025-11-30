#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Insert a new node at beginning
Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Build Intersection List
Node* intersectionList(Node* head1, Node* head2) {
    unordered_set<int> s;
    Node* temp = head1;

    while (temp) {
        s.insert(temp->data);
        temp = temp->next;
    }

    Node* result = NULL;
    temp = head2;

    while (temp) {
        if (s.count(temp->data)) {
            result = insert(result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

// Build Union List
Node* unionList(Node* head1, Node* head2) {
    unordered_set<int> s;
    Node* temp = head1;

    // Insert elements of list1
    while (temp) {
        s.insert(temp->data);
        temp = temp->next;
    }

    // Insert elements of list2
    temp = head2;
    while (temp) {
        s.insert(temp->data);
        temp = temp->next;
    }

    // Build union list from set
    Node* result = NULL;
    for (int val : s) {
        result = insert(result, val);
    }

    return result;
}

int main() {
    // Example:
    // head1: 10 -> 15 -> 4 -> 20
    // head2: 8 -> 4 -> 2 -> 10

    Node* head1 = NULL;
    head1 = insert(head1, 20);
    head1 = insert(head1, 4);
    head1 = insert(head1, 15);
    head1 = insert(head1, 10);

    Node* head2 = NULL;
    head2 = insert(head2, 10);
    head2 = insert(head2, 2);
    head2 = insert(head2, 4);
    head2 = insert(head2, 8);

    Node* inter = intersectionList(head1, head2);
    Node* uni = unionList(head1, head2);

    cout << "Intersection List: ";
    printList(inter);

    cout << "Union List: ";
    printList(uni);

    return 0;
}

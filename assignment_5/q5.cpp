#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at end
Node* insert(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to get length of linked list
int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection node
Node* getIntersectionNode(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move the longer list ahead by the difference in lengths
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    // Traverse both lists together until intersection is found
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)  // compare memory addresses, not data
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // no intersection
}

int main() {
    // Creating nodes for shared part (8 -> 5 -> NULL)
    Node* common = new Node{8, new Node{5, NULL}};

    // Creating first list: 4 -> 1 -> 8 -> 5
    Node* head1 = new Node{4, new Node{1, common}};

    // Creating second list: 5 -> 6 -> 1 -> 8 -> 5
    Node* head2 = new Node{5, new Node{6, new Node{1, common}}};

    Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        cout << "Intersected at " << intersection->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}

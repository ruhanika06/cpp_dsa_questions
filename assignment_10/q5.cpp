#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;

    Node* curr = head;
    while (curr != nullptr) {
        if (visited.count(curr)) {
            return true; // cycle found
        }
        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> (back to 2)

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // creates loop

    if (hasCycle(n1))
        cout << "true";
    else
        cout << "false";

    return 0;
}

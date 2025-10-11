#include <iostream>
using namespace std;

// Node structure for polynomial term
struct Node {
    int coeff;  // Coefficient
    int pow;    // Power
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

// Function to add two polynomials
Node* addPolynomial(Node* poly1, Node* poly2) {
    Node dummy(0, 0);
    Node* tail = &dummy;

    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0)
                tail->next = new Node(sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->pow > poly2->pow) {
            tail->next = new Node(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else {
            tail->next = new Node(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        if (tail->next) tail = tail->next;
    }

    // Append remaining nodes
    while (poly1) {
        tail->next = new Node(poly1->coeff, poly1->pow);
        tail = tail->next;
        poly1 = poly1->next;
    }
    while (poly2) {
        tail->next = new Node(poly2->coeff, poly2->pow);
        tail = tail->next;
        poly2 = poly2->next;
    }

    return dummy.next;
}

// Function to print a polynomial
void printPolynomial(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a new node and append at end
void appendNode(Node*& head, int coeff, int pow) {
    Node* newNode = new Node(coeff, pow);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Main function to demonstrate
int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    // Polynomial 1: 5x^2 + 4x + 2
    appendNode(poly1, 5, 2);
    appendNode(poly1, 4, 1);
    appendNode(poly1, 2, 0);

    // Polynomial 2: 3x^3 + 2x + 1
    appendNode(poly2, 3, 3);
    appendNode(poly2, 2, 1);
    appendNode(poly2, 1, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);

    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* sum = addPolynomial(poly1, poly2);

    cout << "Sum: ";
    printPolynomial(sum);

    return 0;
}

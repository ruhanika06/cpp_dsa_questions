#include <iostream>
#include <list>
#include <queue>  // For circular list using queue
using namespace std;

// Function to display circular queue (simulating circular linked list)
void displayCircular(queue<int> q) {
    if (q.empty()) {
        cout << "Circular List is empty\n";
        return;
    }
    int size = q.size();
    for (int i = 0; i < size; i++) {
        int val = q.front();
        cout << val << " ";
        q.pop();
        q.push(val); // reinsert to maintain order (simulate circular behavior)
    }
    cout << endl;
}

int main() {
    // ----- Doubly Linked List -----
    list<int> dll;
    int n, val;

    cout << "Enter number of elements in Doubly Linked List: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.push_back(val);
    }

    cout << "\nOriginal Doubly Linked List:\n";
    for (int x : dll) cout << x << " ";
    cout << endl;

    // Remove even elements
    dll.remove_if([](int x) { return x % 2 == 0; });

    cout << "After removing even elements (Doubly Linked List):\n";
    for (int x : dll) cout << x << " ";
    cout << endl;


    // ----- Circular Singly Linked List (simulated using queue) -----
    queue<int> circularList;
    cout << "\nEnter number of elements in Circular Singly Linked List: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        circularList.push(val);
    }

    cout << "\nOriginal Circular Linked List:\n";
    displayCircular(circularList);

    // Remove even elements (create a new queue)
    int size = circularList.size();
    queue<int> temp;
    for (int i = 0; i < size; i++) {
        int front = circularList.front();
        circularList.pop();
        if (front % 2 != 0)
            temp.push(front);
    }
    circularList = temp;

    cout << "After removing even elements (Circular Linked List):\n";
    displayCircular(circularList);

    return 0;
}

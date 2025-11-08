#include <iostream>
#include <queue>
using namespace std;

// ---------------------- STACK USING TWO QUEUES ----------------------
class Stack2Q {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack (2Q) is empty!\n";
            return;
        }
        cout << "Popped: " << q1.front() << "\n";
        q1.pop();
    }

    void top() {
        if (q1.empty())
            cout << "Stack (2Q) is empty!\n";
        else
            cout << "Top element: " << q1.front() << "\n";
    }

    bool empty() {
        return q1.empty();
    }
};

// ---------------------- STACK USING ONE QUEUE ----------------------
class Stack1Q {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack (1Q) is empty!\n";
            return;
        }
        cout << "Popped: " << q.front() << "\n";
        q.pop();
    }

    void top() {
        if (q.empty())
            cout << "Stack (1Q) is empty!\n";
        else
            cout << "Top element: " << q.front() << "\n";
    }

    bool empty() {
        return q.empty();
    }
};

// ---------------------- MAIN MENU ----------------------
int main() {
    Stack1Q s1;
    Stack2Q s2;

    int choice, stackType, val;

    while (true) {
        cout << "\n==============================\n";
        cout << "   STACK USING QUEUES (MENU)\n";
        cout << "==============================\n";
        cout << "Choose Stack Type:\n";
        cout << "1. Stack using TWO Queues\n";
        cout << "2. Stack using ONE Queue\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> stackType;

        if (stackType == 3) break;

        while (true) {
            cout << "\n--- Operations Menu ---\n";
            cout << "1. Push\n2. Pop\n3. Top\n4. Check Empty\n5. Change Stack Type / Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 5) break;

            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    if (stackType == 1) s2.push(val);
                    else s1.push(val);
                    break;

                case 2:
                    if (stackType == 1) s2.pop();
                    else s1.pop();
                    break;

                case 3:
                    if (stackType == 1) s2.top();
                    else s1.top();
                    break;

                case 4:
                    if (stackType == 1)
                        cout << (s2.empty() ? "Stack is empty\n" : "Stack is NOT empty\n");
                    else
                        cout << (s1.empty() ? "Stack is empty\n" : "Stack is NOT empty\n");
                    break;

                default:
                    cout << "Invalid choice!\n";
            }
        }
    }

    cout << "Program terminated.\n";
    return 0;
}

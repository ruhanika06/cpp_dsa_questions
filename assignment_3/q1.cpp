#include <iostream>
using namespace std;
// maximum size of stack
#define MAX 10   

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // check if stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // push element into stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    // pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // display top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if (s.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is NOT Empty.\n";
                break;
            case 4:
                if (s.isFull())
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is NOT Full.\n";
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
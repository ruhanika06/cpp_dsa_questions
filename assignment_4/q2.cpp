#include <iostream>
#include <queue>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear, count;
public:
    CircularQueue() {
        front = rear = -1;
        count = 0;
    }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == SIZE; }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = val;
        if (front == -1) front = 0;
        count++;
        cout << val << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front = (front + 1) % SIZE;
        count--;
        if (count == 0) front = rear = -1;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty!\n";
        else cout << "Front element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % SIZE] << " ";
        cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60); // full
    cq.display();
}

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    // Heapify Up (for insert)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    // Heapify Down (for delete/extract)
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert element into Priority Queue
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Return maximum element (highest priority)
    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Remove and return maximum element
    int extractMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    // Increase key at a given index
    void increaseKey(int index, int newVal) {
        if (index < 0 || index >= heap.size()) {
            cout << "Invalid Index!" << endl;
            return;
        }
        heap[index] = newVal;
        heapifyUp(index);
    }

    // Display the priority queue
    void display() {
        cout << "Priority Queue (Heap): ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};


int main() {
    PriorityQueue pq;
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    pq.insert(50);
    pq.insert(10);

    pq.display();

    cout << "Maximum Element: " << pq.getMax() << endl;

    cout << "Extracted Max: " << pq.extractMax() << endl;
    pq.display();

    pq.increaseKey(2, 45);  // Increase value at index 2
    cout << "After increasing key: ";
    pq.display();

    return 0;
}

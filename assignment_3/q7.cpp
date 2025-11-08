#include <iostream>
using namespace std;

class Stack {
    long long *arr;
    int topIdx, cap;
    long long minElement;
public:
    Stack(int c) {
        cap=c; arr=new long long[c]; topIdx=-1;
    }
    ~Stack() { delete[] arr; }

    bool isEmpty() { return topIdx==-1; }
    bool isFull() { return topIdx==cap-1; }

    void push(long long x) {
        if(isFull()) { cout<<"Stack Overflow\n"; return; }
        if(isEmpty()) {
            minElement = x;
            arr[++topIdx] = x;
        } else if(x < minElement) {
            arr[++topIdx] = 2*x - minElement;
            minElement = x;
        } else {
            arr[++topIdx] = x;
        }
    }

    void pop() {
        if(isEmpty()) { cout<<"Stack Underflow\n"; return; }
        long long t = arr[topIdx--];
        if(t < minElement)
            minElement = 2*minElement - t;
    }

    long long top() {
        if(isEmpty()) return -1;
        long long t = arr[topIdx];
        if(t < minElement) return minElement;
        return t;
    }

    long long getMin() {
        if(isEmpty()) return -1;
        return minElement;
    }
};

int main() {
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;
    Stack st(n);

    st.push(5);
    st.push(3);
    st.push(7);
    cout << "Min: " << st.getMin() << endl;  // 3

    st.pop();
    cout << "Top: " << st.top() << endl;     // 3
    cout << "Min: " << st.getMin() << endl;  // 3

    st.pop();
    cout << "Min: " << st.getMin() << endl;  // 5

    return 0;
}

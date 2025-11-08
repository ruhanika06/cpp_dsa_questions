#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int topIdx, cap;
public:
    Stack(int c) { cap = c; arr = new int[c]; topIdx = -1; }
    ~Stack() { delete[] arr; }

    bool isEmpty() { return topIdx == -1; }
    bool isFull() { return topIdx == cap - 1; }

    void push(int x) {
        if (!isFull()) arr[++topIdx] = x;
    }

    int pop() {
        if (isEmpty()) return -1;
        return arr[topIdx--];
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[topIdx];
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temp[n], ans[n];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> temp[i];

    Stack s(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.isEmpty() && temp[s.top()] <= temp[i])
            s.pop();

        if (s.isEmpty())
            ans[i] = 0;
        else
            ans[i] = s.top() - i;

        s.push(i);
    }

    cout << "Days until a warmer temperature:\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}

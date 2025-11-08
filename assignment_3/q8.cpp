#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int topIdx, cap;
public:
    Stack(int c) { cap=c; arr=new int[c]; topIdx=-1; }
    ~Stack() { delete[] arr; }

    bool isEmpty() { return topIdx==-1; }
    bool isFull() { return topIdx==cap-1; }

    void push(int x) {
        if(!isFull()) arr[++topIdx]=x;
    }

    int pop() {
        if(isEmpty()) return -1;
        return arr[topIdx--];
    }

    int top() {
        if(isEmpty()) return -1;
        return arr[topIdx];
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n], nge[n];
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    Stack s(n);

    for(int i=n-1; i>=0; i--) {
        while(!s.isEmpty() && s.top() <= arr[i])
            s.pop();

        if(s.isEmpty())
            nge[i] = -1;
        else
            nge[i] = s.top();

        s.push(arr[i]);
    }

    cout << "Next Greater Elements:\n";
    for(int i=0; i<n; i++)
        cout << nge[i] << " ";
    cout << endl;

    return 0;
}

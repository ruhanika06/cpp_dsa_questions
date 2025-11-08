#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    cout << "Binary numbers from 1 to " << n << " are: ";

    for (int i = 1; i <= n; i++) {
        string s = q.front();
        q.pop();
        cout << s;
        if (i != n) cout << ", ";

        q.push(s + "0");
        q.push(s + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    generateBinaryNumbers(n);
    return 0;
}

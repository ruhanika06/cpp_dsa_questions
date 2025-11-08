#include <iostream>
#include <string>
using namespace std;

bool canSplit(string s) {
    int n = s.length();
    // Split into three parts (i,j,k)
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j - i);
            string c = s.substr(j);

            // Check if one substring occurs in both others
            if ((a.find(b) != string::npos && c.find(b) != string::npos) ||
                (b.find(a) != string::npos && c.find(a) != string::npos) ||
                (a.find(c) != string::npos && b.find(c) != string::npos))
                return true;
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    if (canSplit(s)) cout << "Yes, can be split as required.";
    else cout << "No, cannot be split.";
    return 0;
}

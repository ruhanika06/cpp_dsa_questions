#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for (char c : s) {

        // If opening bracket, push
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // If closing bracket, check match
        else if (c == ')' || c == '}' || c == ']') {

            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }

    return st.empty();  // stack must be empty
}

int main() {
    string expr;
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}

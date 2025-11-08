#include <iostream>
#include <stack>
#include <string>
#include <cctype>   // for isdigit
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // If character is a space, skip
        if (ch == ' ')
            continue;

        // If operand (number), push into stack
        else if (isdigit(ch)) {
            s.push(ch - '0');  // convert char to int
        }
        // If operator, pop two operands and apply
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();  // Final result
}

int main() {
    string exp;
    cout << "Enter Postfix expression (single-digit operands): ";
    getline(cin, exp);

    cout << "Result = " << evaluatePostfix(exp) << endl;
    return 0;
}
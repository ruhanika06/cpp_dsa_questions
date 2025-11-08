#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-') 
        return 1;
    if(op == '*' || op == '/') 
        return 2;
    if(op == '^') 
        return 3;
    return 0;
}

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for(int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If operand -> add to result
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        // If '(' -> push to stack
        else if(ch == '(') {
            s.push(ch);
        }
        // If ')' -> pop until '('
        else if(ch == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop(); // remove '('
        }
        // If operator
        else if(isOperator(ch)) {
            while(!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
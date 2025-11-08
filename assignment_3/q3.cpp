#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    stack<char> st;

    // Push all characters into stack
    for (int i = 0; i < str.length(); i++) {
    st.push(str[i]);
    }


    // Pop all characters to get reversed string
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    cout << "Reversed string: " << reversed << endl;
    return 0;
}
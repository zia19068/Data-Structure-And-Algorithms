#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPrecedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPrefix(string infix) {
    string prefix = "";
    stack<char> st;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        if (isalnum(c)) {
            prefix = c + prefix;
        } 
        else if (c == ')') {
            st.push(c);
        } 
        else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                prefix = st.top() + prefix;
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } 
        else if (isOperator(c)) {
            while (!st.empty() && getPrecedence(st.top()) > getPrecedence(c)) {
                prefix = st.top() + prefix;
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        prefix = st.top() + prefix;
        st.pop();
    }

    return prefix;
}

int main() {
    string exp = "(A-B/C)*(A/K-L)";
    
    cout << "Infix: " << exp << endl;
    cout << "Prefix: " << infixToPrefix(exp) << endl;

    return 0;
}

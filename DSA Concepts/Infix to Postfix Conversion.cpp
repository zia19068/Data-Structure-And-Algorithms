#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char d;
    Node* next;
    Node(char v) {
        d = v;
        next = NULL;
    }
};

class Stack {
public:
    Node* t;
    Stack() { t = NULL; }

    void push(char v) {
        Node* n = new Node(v);
        n->next = t;
        t = n;
    }

    char pop() {
        if (!t) return '\0';
        Node* temp = t;
        char val = temp->d;
        t = t->next;
        delete temp;
        return val;
    }

    char peek() {
        return t ? t->d : '\0';
    }

    bool isEmpty() {
        return t == NULL;
    }
};

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string convert(string s) {
    Stack st;
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            res += c;
        } 
        else if (c == '(') {
            st.push('(');
        } 
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                res += st.pop();
            }
            st.pop();
        } 
        else {
            while (!st.isEmpty() && prec(c) <= prec(st.peek())) {
                res += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        res += st.pop();
    }

    return res;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << exp << endl;
    cout << "Postfix: " << convert(exp) << endl;
    return 0;
}

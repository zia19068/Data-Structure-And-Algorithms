#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string d;
    Node* next;
    Node(string v) {
        d = v;
        next = NULL;
    }
};

class Stack {
public:
    Node* t;
    Stack() { t = NULL; }

    void push(string v) {
        Node* n = new Node(v);
        n->next = t;
        t = n;
    }

    string pop() {
        if (!t) return "";
        Node* temp = t;
        string val = temp->d;
        t = t->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return t == NULL;
    }
};

bool isOp(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string convert(string s) {
    Stack st;

    for (int i = 0; i < s.length(); i++) {
        if (!isOp(s[i])) {
            string op(1, s[i]);
            st.push(op);
        } else {
            string v1 = st.pop();
            string v2 = st.pop();
            string exp = "(" + v2 + s[i] + v1 + ")";
            st.push(exp);
        }
    }
    return st.pop();
}

int main() {
    string post = "ab+c*d-";
    cout << "Postfix: " << post << endl;
    cout << "Infix: " << convert(post) << endl;
    return 0;
}

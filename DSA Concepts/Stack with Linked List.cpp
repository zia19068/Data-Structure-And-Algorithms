#include <iostream>
using namespace std;

class Node {
public:
    int d;
    Node* next;
    Node(int v) {
        d = v;
        next = NULL;
    }
};

class Stack {
public:
    Node* t;

    Stack() {
        t = NULL;
    }

    void push(int v) {
        Node* newNode = new Node(v);
        newNode->next = t;
        t = newNode;
    }

    void pop() {
        if (t == NULL) {
            cout << "Empty" << endl;
            return;
        }
        Node* temp = t;
        t = t->next;
        delete temp;
    }

    int peek() {
        if (t == NULL) return -1;
        return t->d;
    }

    bool isEmpty() {
        return t == NULL;
    }

    void show() {
        Node* temp = t;
        while (temp != NULL) {
            cout << temp->d << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.show();
    cout << "Top: " << s.peek() << endl;
    s.pop();
    s.show();
    return 0;
}

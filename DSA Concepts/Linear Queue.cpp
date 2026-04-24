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

class Queue {
public:
    Node *f, *r;

    Queue() {
        f = r = NULL;
    }

    void enqueue(int v) {
        Node* n = new Node(v);
        if (r == NULL) {
            f = r = n;
            return;
        }
        r->next = n;
        r = n;
    }

    void dequeue() {
        if (f == NULL) return;
        Node* t = f;
        f = f->next;
        if (f == NULL) r = NULL;
        delete t;
    }

    void show() {
        Node* t = f;
        while (t != NULL) {
            cout << t->d << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.show();
    q.dequeue();
    q.show();
    return 0;
}

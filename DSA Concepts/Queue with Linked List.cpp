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
        Node* temp = f;
        f = f->next;
        if (f == NULL) r = NULL;
        delete temp;
    }

    int peek() {
        return (f != NULL) ? f->d : -1;
    }

    void show() {
        Node* temp = f;
        while (temp != NULL) {
            cout << temp->d << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.show();
    q.dequeue();
    q.show();
    return 0;
}

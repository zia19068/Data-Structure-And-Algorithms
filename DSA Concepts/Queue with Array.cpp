#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
public:
    int a[SIZE];
    int f, r;

    Queue() {
        f = r = -1;
    }

    void enqueue(int x) {
        if (r == SIZE - 1) {
            cout << "Full" << endl;
            return;
        }
        if (f == -1) f = 0;
        a[++r] = x;
    }

    void dequeue() {
        if (f == -1 || f > r) {
            cout << "Empty" << endl;
            return;
        }
        f++;
    }

    int peek() {
        if (f == -1 || f > r) return -1;
        return a[f];
    }

    void show() {
        for (int i = f; i <= r; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.show();
    q.dequeue();
    q.show();
    return 0;
}

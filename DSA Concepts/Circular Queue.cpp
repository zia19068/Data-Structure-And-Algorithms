#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
public:
    int a[SIZE];
    int f, r;

    CircularQueue() {
        f = r = -1;
    }

    void enqueue(int x) {
        if ((r + 1) % SIZE == f) {
            cout << "Queue Full" << endl;
            return;
        }
        if (f == -1) f = 0;
        r = (r + 1) % SIZE;
        a[r] = x;
    }

    void dequeue() {
        if (f == -1) {
            cout << "Queue Empty" << endl;
            return;
        }
        if (f == r) {
            f = r = -1;
        } else {
            f = (f + 1) % SIZE;
        }
    }

    int peek() {
        if (f == -1) return -1;
        return a[f];
    }

    void display() {
        if (f == -1) {
            cout << "Empty" << endl;
            return;
        }
        int i = f;
        while (true) {
            cout << a[i] << " ";
            if (i == r) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();
    q.dequeue();
    q.enqueue(60); 
    q.display();

    return 0;
}

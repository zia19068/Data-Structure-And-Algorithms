#include <iostream>

using namespace std;

class Queue {
private:
    int* items;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        items = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue Full" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        items[rear] = element;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty" << endl;
            return -1;
        }
        int element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~Queue() {
        delete[] items;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}

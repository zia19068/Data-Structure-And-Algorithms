#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
public:
    int a[SIZE];
    int t;

    Stack() {
        t = -1;
    }

    void push(int x) {
        if (t >= SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        a[++t] = x;
    }

    void pop() {
        if (t < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        t--;
    }

    int top() {
        if (t < 0) {
            return -1;
        }
        return a[t];
    }

    bool isEmpty() {
        return (t < 0);
    }

    void display() {
        for (int i = t; i >= 0; i--) {
            cout << a[i] << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.top() << endl;
    
    s.pop();
    s.display();

    return 0;
}

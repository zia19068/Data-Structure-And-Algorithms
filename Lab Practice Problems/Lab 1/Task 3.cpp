/*Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/
#include <iostream>
using namespace std;

class Box {
    int* p;

public:
    Box(int v) {
        p = new int(v);
    }

    ~Box() {
        delete p;
        cout << "Destructor called." << endl;
    }

    Box(const Box& b) {
        p = new int(*b.p);
    }

    Box& operator=(const Box& b) {
        if (this != &b) {
            delete p;
            p = new int(*b.p);
        }
        return *this;
    }

    void setVal(int v) {
        *p = v;
    }

    void show() {
        cout << "Value: " << *p << " Address: " << p << endl;
    }
};

int main() {
    Box b1(10);
    Box b2 = b1; 

    cout << "Deep Copy Constructor:" << endl;
    b1.show();
    b2.show();

    b1.setVal(20);
    cout << "After Modifying b1:" << endl;
    b1.show();
    b2.show();

    Box b3(30);
    b3 = b1;

    cout << "Deep Copy Assignment:" << endl;
    b3.show();

    return 0;
}

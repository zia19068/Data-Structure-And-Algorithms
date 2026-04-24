/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/
#include <iostream>
#include <cstring>
using namespace std;

class Exam {
    char* name;
    char* date;
    double score;

public:
    Exam() {
        name = NULL;
        date = NULL;
        score = 0;
    }

    ~Exam() {
        delete[] name;
        delete[] date;
    }

    void setName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void setDate(const char* d) {
        delete[] date;
        date = new char[strlen(d) + 1];
        strcpy(date, d);
    }

    void setScore(double s) {
        score = s;
    }

    void display() {
    	cout << "------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Score: " << score << endl;
        cout << "------------------" << endl;
    }
};

int main() {
    Exam obj1;
    obj1.setName("Zohiab");
    obj1.setDate("12-05-2024");
    obj1.setScore(85.5);

    cout << "Object 1 Details:" << endl;
    obj1.display();

    Exam obj2 = obj1; 

    cout << "Object 2 Details (Shallow Copy):" << endl;
    obj2.display();

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int marks[5];
    int n = 5;
    int i, j, key;

    cout << "      STUDENT MARKS INSERTION SORT      " << endl;
   
    cout << "Enter marks for 5 students: " << endl;
    for (i = 0; i < n; i++) {
        cin >> marks[i];
    }

    for (i = 1; i < n; i++) {
        key = marks[i];
        j = i - 1;

        while (j >= 0 && marks[j] > key) {
            marks[j + 1] = marks[j];
            j = j - 1;
        }
        marks[j + 1] = key;
    }

    cout << "\n--- Marks in Ascending Order ---" << endl;
    for (i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;
}

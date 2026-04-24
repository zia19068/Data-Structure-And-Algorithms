#include <iostream>
using namespace std;

int main() {
    int s = 5;
    int b = 4;

    int** marks = new int*[s];
    int i;
    for (i = 0; i < s; i++) {
        marks[i] = new int[b];
    }
    int j;
    for (i = 0; i < s; i++) {
        cout << "Enter 4 marks for student " << i + 1 << ": ";
        for (j = 0; j < b; j++) {
            cin >> marks[i][j];
        }
    }

    cout << "\nTotal Marks per Student:" << endl;
    int maxTotal = -1;
    int topper = 0;
    
    for (i = 0; i < s; i++) {
        int stSum = 0;
        for (j = 0; j < b; j++) {
            stSum += marks[i][j];
        }
        cout << "Student " << i + 1 << ": " << stSum << endl;
        
        if (stSum > maxTotal) {
            maxTotal = stSum;
            topper = i + 1;
        }
    }

    cout << "\nAverage Marks per Subject:" << endl;
    
    for (j = 0; j < b; j++) {
        float subSum = 0;
        for (i = 0; i < s; i++) {
            subSum += marks[i][j];
        }
        cout << "Subject " << j + 1 << ": " << subSum / s << endl;
    }

    cout << "\nTopper Student: Student " << topper << " with " << maxTotal << " marks." << endl;
    
    for (i = 0; i < s; i++) {
        delete[] marks[i];
    }
    delete[] marks;

    return 0;
}

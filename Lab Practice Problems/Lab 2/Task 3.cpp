/*Task#3
A university is managing the marks of students in multiple subjects. Each department has a
different number of students. Each student has marks for a fixed number of 5 subjects.
You need to store this data in a appropriate dynamic array where rows = number of departments
and columns = number of students in each department. Then, calculate the highest, lowest and
average marks of each department and display them.*/
#include <iostream>
using namespace std;

int main() {
    int depts;
    int subs = 5;

    cout << "Enter number of departments: ";
    cin >> depts;

    int** counts = new int*[depts]; 
    int*** data = new int**[depts];

    int* stuPerDept = new int[depts];
    int i;
    for (i = 0; i < depts; i++) {
        cout << "Enter number of students in department " << i + 1 << ": ";
        cin >> stuPerDept[i];

        data[i] = new int*[stuPerDept[i]];
        int j,k;
        for (j = 0; j < stuPerDept[i]; j++) {
            data[i][j] = new int[subs];
            cout << "  Enter " << subs << " marks for student " << j + 1 << ": ";
            for (k = 0; k < subs; k++) {
                cin >> data[i][j][k];
            }
        }
    }
    
    for (i = 0; i < depts; i++) {
        int dHigh = -1;
        int dLow = 101; 
        float dTotal = 0;
        int totalMarksCount = stuPerDept[i] * subs;
        int j,k;
        for (j = 0; j < stuPerDept[i]; j++) {
            for ( k = 0; k < subs; k++) {
                int val = data[i][j][k];
                if (val > dHigh) dHigh = val;
                if (val < dLow) dLow = val;
                dTotal += val;
            }
        }

        cout << "\nDepartment " << i + 1 << " Statistics:" << endl;
        cout << "Highest: " << dHigh << endl;
        cout << "Lowest: " << dLow << endl;
        cout << "Average: " << dTotal / totalMarksCount << endl;
    }
    int j;
    for (i = 0; i < depts; i++) {
        for (j = 0; j < stuPerDept[i]; j++) {
            delete[] data[i][j];
        }
        delete[] data[i];
    }
    delete[] data;
    delete[] stuPerDept;

    return 0;
}

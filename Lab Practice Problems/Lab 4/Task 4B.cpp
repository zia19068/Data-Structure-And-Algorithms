#include <iostream>
using namespace std;

int main() {
    int a[5] = {50, 40, 30, 20, 10};
    int b[5] = {50, 40, 30, 20, 10};
    int n = 5;
    int i, j, gap, temp, shellMoves = 0, insertMoves = 0;

    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j = j - 1;
            insertMoves++;
        }
        a[j + 1] = temp;
        insertMoves++;
    }

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = b[i];
            for (j = i; j >= gap && b[j - gap] > temp; j -= gap) {
                b[j] = b[j - gap];
                shellMoves++;
            }
            b[j] = temp;
            shellMoves++;
        }
    }

    cout << "--- Performance Comparison ---" << endl;
    cout << "Insertion Sort Moves: " << insertMoves << endl;
    cout << "Shell Sort Moves:     " << shellMoves << endl;

    if (shellMoves < insertMoves) {
        cout << "\nResult: Shell Sort is faster " << endl;
    } else {
        cout << "\nResult: Insertion Sort is faster for this small size." << endl;
    }

    return 0;
}

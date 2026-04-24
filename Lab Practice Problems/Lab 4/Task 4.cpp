#include <iostream>
using namespace std;

int main() {
    int arr[20];
    int n = 20;
    int i, j, gap, temp;

    cout << "           SHELL SORT PROGRAM           " << endl;
 
    cout << "Enter 20 integers:" << endl;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nGap Sequence used: ";
    for (gap = n / 2; gap > 0; gap /= 2) {
        cout << gap << " ";
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

    cout << "\n\nSorted Array: " << endl;
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
   

    return 0;
}

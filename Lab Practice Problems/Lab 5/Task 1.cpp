#include <iostream>
using namespace std;
int main() {
    int arr[] = {12, 5, 18, 2, 9, 1, 15, 7};
    int n = 8;
    int i, temp, gap;
    bool swapped;
    cout << " COMB SORT PROGRAM " << endl;
    gap = n;
    swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }
        cout << "Current Gap: " << gap << endl;
        swapped = false;
        for (i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
    cout << "\nSorted Array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
       return 0;
}

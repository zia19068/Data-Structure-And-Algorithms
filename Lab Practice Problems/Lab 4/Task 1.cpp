#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int n = 10,i,j;
    bool swapped;

    cout << "Enter 10 integers:" << endl;
    for ( i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    for ( i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for ( i = 0; i < n - 1; i++) {
        swapped = false;
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    cout << "Array after sorting: ";
    for ( i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

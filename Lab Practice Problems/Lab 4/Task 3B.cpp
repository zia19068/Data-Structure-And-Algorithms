/*Modify Insertion Sort to arrange numbers in descending order. Test with: {15, 2, 78, 25,
63}*/
#include <iostream>
using namespace std;

int main() {
    int arr[] = {15, 2, 78, 25, 63};
    int n = 5;
    int i, j, key;
    cout << "      DESCENDING INSERTION SORT         " << endl;
   

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    cout << "Sorted in Descending Order: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}

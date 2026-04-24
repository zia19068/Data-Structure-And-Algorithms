#include <iostream>
using namespace std;

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = 5,i,j;
    int swapCount = 0;

    cout << "--- Integer Selection Sort with Swap Count ---" << endl;

    for ( i = 0; i < n - 1; i++) {
        int minIdx = i;
        for ( j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        if (minIdx != i) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
            swapCount++;
        }
    }

    cout << "Sorted Array: ";
    for ( i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal Swaps Performed: " << swapCount << endl;

    return 0;
}

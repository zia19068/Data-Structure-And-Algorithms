/* Compare the performance of Comb Sort with Bubble Sort for a reverse-sorted array {9,
8, 7, 6, 5, 4, 3, 2, 1}. Which one is faster and why?*/
#include <iostream>
using namespace std;
int main() {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int b[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 9;
    int i, j, temp, gap, bubbleCount = 0, combCount = 0;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            bubbleCount++;
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    gap = n;
    swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        swapped = false;
        for (i = 0; i < n - gap; i++) {
            combCount++;
            if (b[i] > b[i + gap]) {
                temp = b[i];
                b[i] = b[i + gap];
                b[i + gap] = temp;
                swapped = true;
            }
        }
    }
    cout << "--- Performance Results ---" << endl;
    cout << "Bubble Sort Comparisons: " << bubbleCount << endl;
    cout << "Comb Sort Comparisons:   " << combCount << endl;
    return 0;
}

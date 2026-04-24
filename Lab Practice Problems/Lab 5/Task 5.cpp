/*Compare Binary Search and Interpolation Search for the list:
{5, 10, 15, 20, 25, 30, 35, 40, 45, 50}
 Search for 45
 Show number of comparisons each method makes
 Conclude which one is more efficient in this case.*/
#include <iostream>
using namespace std;
int main() {
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int n = 10;
    int target = 45;
    int low, high, mid, pos, binCount = 0, intCount = 0;
    low = 0;
    high = n - 1;
    while (low <= high) {
        binCount++;
        mid = low + (high - low) / 2;
        if (arr[mid] == target) break;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    low = 0;
    high = n - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        intCount++;
        pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        if (arr[pos] == target) break;
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    cout << "Performance Comparison: " << endl;
    cout << "Binary Search Comparisons: " << binCount << endl;
    cout << "Interpolation Search Comparisons: " << intCount << endl;
    return 0;
}

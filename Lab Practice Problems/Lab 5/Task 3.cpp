#include <iostream>
using namespace std;
int main() {
    int rollNumbers[] = {101, 105, 110, 120, 135, 150};
    int n = 6;
    int target, low, high, mid, comparisons;
    bool found;
    cout << "UNIVERSITY REGISTRATION SYSTEM" << endl;
    cout << "Enter Roll Number to search: ";
    cin >> target;
    low = 0;
    high = n - 1;
    comparisons = 0;
    found = false;
    while (low <= high) {
        comparisons++;
        mid = low + (high - low) / 2;
        if (rollNumbers[mid] == target) {
            found = true;
            break;
        } else if (rollNumbers[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (found) {
        cout << "Result: Roll number found" << endl;
    } else {
        cout << "Result: Roll number not found" << endl;
    }
    cout << "Total Comparisons Made: " << comparisons << endl;
    return 0;
}

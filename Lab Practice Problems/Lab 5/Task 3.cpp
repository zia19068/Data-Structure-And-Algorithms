/*A university stores roll numbers of students in a sorted database. When an admin wants to check
whether a student is registered, the system uses Binary Search instead of checking each roll
number one by one.
Tasks:
1. Write a C++ program to search for a roll number in the sorted list:
{101, 105, 110, 120, 135, 150}
 Input: a roll number from the user
 Output: "Roll number found" or "Roll number not found"
2. Enhance the program to count and display how many comparisons were made while
searching.
Example: Searching for 120 should show both the result and the number of steps taken.*/
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

/*Write a C++ program using Interpolation Search to find a product price from the sorted
list:
{10, 20, 30, 40, 50, 60, 70, 80}
 Input: a price entered by the user
 Output: "Price found at position X" or "Price not available"*/
#include <iostream>
using namespace std;
int main() {
    int prices[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = 8;
    int target, low, high, pos;
    bool found;
    cout << "E-COMMERCE PRICE SEARCH" << endl;
    cout << "Enter product price to search: ";
    cin >> target;
    low = 0;
    high = n - 1;
    found = false;
    while (low <= high && target >= prices[low] && target <= prices[high]) {
        pos = low + (((double)(high - low) / (prices[high] - prices[low])) * (target - prices[low]));
        if (prices[pos] == target) {
            cout << "Price found at position " << pos << endl;
            found = true;
            break;
        }
        if (prices[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    if (!found) {
        cout << "Price not available" << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    string cities[5];
    int n = 5,i,j;

    cout << "      CITY NAME SELECTION SORT          " << endl;

    cout << "Enter 5 city names:" << endl;
    for ( i = 0; i < n; i++) {
        cin >> cities[i];
    }

    cout << "\n--- Cities Before Sorting ---" << endl;
    for (i = 0; i < n; i++) {
        cout << cities[i] << " ";
    }
    cout << endl;

    for ( i = 0; i < n - 1; i++) {
        int minIdx = i;
        for ( j = i + 1; j < n; j++) {
            if (cities[j] < cities[minIdx]) {
                minIdx = j;
            }
        }
        string temp = cities[minIdx];
        cities[minIdx] = cities[i];
        cities[i] = temp;
    }

    cout << "\n--- Cities After Sorting ---" << endl;
    for ( i = 0; i < n; i++) {
        cout << cities[i] << " ";
    }
    

    return 0;
}

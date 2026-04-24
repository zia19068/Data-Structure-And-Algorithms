#include <iostream>
using namespace std;

int linear_search(int a[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (a[i] == k) return i;
    }
    return -1;
}

int binary_search(int a[], int n, int k) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == k) return m;
        if (a[m] < k) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int interpolation_search(int a[], int n, int k) {
    int l = 0, r = n - 1;
    while (l <= r && k >= a[l] && k <= a[r]) {
        if (l == r) {
            if (a[l] == k) return l;
            return -1;
        }
        int p = l + (((double)(r - l) / (a[r] - a[l])) * (k - a[l]));
        if (a[p] == k) return p;
        if (a[p] < k) l = p + 1;
        else r = p - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = 8;
    int key = 50;

    int r1 = linear_search(arr, n, key);
    int r2 = binary_search(arr, n, key);
    int r3 = interpolation_search(arr, n, key);

    cout << "Linear: " << r1 << endl;
    cout << "Binary: " << r2 << endl;
    cout << "Interpolation: " << r3 << endl;

    return 0;
}

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void bubble(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

void selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[m]) m = j;
        }
        swap(a[i], a[m]);
    }
}

void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[50], R[50];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void merge_sort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int partition(int a[], int l, int h) {
    int p = a[h];
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (a[j] < p) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quick_sort(int a[], int l, int h) {
    if (l < h) {
        int pi = partition(a, l, h);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, h);
    }
}

void comb(int a[], int n) {
    int g = n;
    bool s = true;
    while (g != 1 || s) {
        g = (g * 10) / 13;
        if (g < 1) g = 1;
        s = false;
        for (int i = 0; i < n - g; i++) {
            if (a[i] > a[i + g]) {
                swap(a[i], a[i + g]);
                s = true;
            }
        }
    }
}

void show(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {45, 22, 11, 89, 7, 33};
    int n = 6;
    
    quick_sort(arr, 0, n - 1);
    show(arr, n);
    
    return 0;
}

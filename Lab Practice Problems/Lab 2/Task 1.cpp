/*Task#1
You are tasked with implementing a dynamic matrix class in C++ that supports the following
operations: Dynamic Matrix Creation: Create a dynamic 2D array (matrix) with rows and columns
specified by the user. Matrix Resizing: Implement a method to resize the matrix. The new size
should be provided as input (new rows and columns). If the new size is larger, initialize the new
elements with a given value. If the new size is smaller, truncate the matrix. Matrix Transposition:
Implement a method to transpose the matrix (rows become columns and vice versa). Matrix Printing: Implement a method to print the matrix. After add 2 to each odd index then print the
array. Memory Deallocation: Ensure proper memory management, including deallocation of the
dynamic matrix when no longer needed.*/
#include <iostream>
using namespace std;
class Matrix {
private:
    int** ptr;
    int rows;
    int cols;
    void clear() {
        if (ptr != NULL) {
        	int i;
            for (i = 0; i < rows; ++i) {
                delete[] ptr[i];
            }
            delete[] ptr;
            ptr = NULL;
        }    }
public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        ptr = new int*[rows];
        int i;
        for (i = 0; i < rows; ++i) {
            ptr[i] = new int[cols]();
        }    }
    ~Matrix() {
        clear();
    }
    void resize(int newR, int newC, int fill) {
        int** temp = new int*[newR];
        int i,j;
        for (i = 0; i < newR; ++i) {
            temp[i] = new int[newC];
            for (j = 0; j < newC; ++j) {
                if (i < rows && j < cols) {
                    temp[i][j] = ptr[i][j];
                } else {
                    temp[i][j] = fill;
                } } }
        clear();
        ptr = temp;
        rows = newR;
        cols = newC;
    }
    void transpose() {
        int** temp = new int*[cols];
        int i,j;
        for (i = 0; i < cols; ++i) {
            temp[i] = new int[rows];
            for (j = 0; j < rows; ++j) {
                temp[i][j] = ptr[j][i];
            } }
        clear();
        ptr = temp;
        int swap = rows;
        rows = cols;
        cols = swap;
    }
    void print() {
    	int i,j;
        for (i = 0; i < rows; ++i) {
            for (j = 0; j < cols; ++j) {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }    }
    void taskPrint() {
    	int i,j;
        for (i = 0; i < rows; ++i) {
            for (j = 0; j < cols; ++j) {
                if (i % 2 != 0 || j % 2 != 0) {
                    ptr[i][j] += 2;
                }
                cout << ptr[i][j] << " ";    }
            cout << endl;        }    }
    void set(int r, int c, int v) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            ptr[r][c] = v;
        }    } };
int main() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    Matrix m(r, c);
    cout << "Enter values:" << endl;
    int i,j;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            int v;
            cin >> v;
            m.set(i, j, v);
        }    }
    cout << "Original:" << endl;
    m.print();
    cout << "Transposed:" << endl;
    m.transpose();
    m.print();
    int nr, nc;
    cout << "Enter resize rows and cols: ";
    cin >> nr >> nc;
    m.resize(nr, nc, 0);
    cout << "Final with odd index update:" << endl;
    m.taskPrint();
    return 0;}

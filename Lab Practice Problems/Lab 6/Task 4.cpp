/*Task # 04: (N-Queens Problem)

You are given a chessboard of size N × N. The task is to place N queens on the board such that
no two queens attack each other.
     A queen can attack horizontally, vertically, and diagonally.
 Print two valid arrangement of queens using recursion + backtracking.
    */
#include <iostream>
using namespace std;
int board[20];
int solutionsFound = 0;
bool isSafe(int row, int col, int n) {
    int i;
    for (i = 0; i < row; i++) {
        if (board[i] == col) {
            return false;
        }
        
        int rowDiff = row - i;
        int colDiff = col - board[i];
        
        if (colDiff < 0) {
            colDiff = -colDiff;
        }
        
        if (rowDiff == colDiff) {
            return false;
        }
    }
    return true;
}
void printBoard(int n) {
    int i, j;
    cout << "Solution #" << solutionsFound << ":" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

void solve(int row, int n) {
    if (solutionsFound >= 2) {
        return;
    }

    if (row == n) {
        solutionsFound++;
        printBoard(n);
        return;
    }

    int col;
    for (col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row] = col;
            solve(row + 1, n);
            board[row] = -1; 
        }
    }
}

int main() {
    int n;
    cout << "Enter board size : ";
    cin >> n;

    if (n < 4 && n != 1) {
        cout << "No solutions exist for size " << n << endl;
    } else {
        solve(0, n);
    }

    return 0;
}

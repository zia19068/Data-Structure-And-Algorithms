/*Task # 05: (Rat in a Maze)

A rat is placed at the top-left corner (0,0) of a maze represented by a grid of 0s and 1s.
 0 => blocked path
 1 => open path
The rat can move Down, Right, Up, or Left but cannot revisit a cell.
The goal is to find all possible paths from (0,0) to (N-1, N-1) using backtracking.*/
#include <iostream>
#include <string>
using namespace std;

#define MAX 5
int maze[MAX][MAX];
int N;
bool isSafe(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N && maze[r][c] == 1);
}

void findPaths(int r, int c, string path) {
    if (r == N - 1 && c == N - 1) {
        cout << "Path Found: " << path << endl;
        return;
    }

    int originalValue = maze[r][c];
    maze[r][c] = 2; 

    if (isSafe(r + 1, c)) {
        findPaths(r + 1, c, path + "D");
    }

    if (isSafe(r, c + 1)) {
        findPaths(r, c + 1, path + "R");
    }

    if (isSafe(r - 1, c)) {
        findPaths(r - 1, c, path + "U");
    }
    if (isSafe(r, c - 1)) {
        findPaths(r, c - 1, path + "L");
    }
    maze[r][c] = originalValue;
}
int main() {
    int i, j;
    cout << "Enter size of maze (max 5): ";
    cin >> N;
    cout << "Enter the maze :" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }
    if (maze[0][0] == 0 || maze[N-1][N-1] == 0) {
        cout << "No path possible" << endl;
    } else {
        findPaths(0, 0, "");
    }
    return 0;
}

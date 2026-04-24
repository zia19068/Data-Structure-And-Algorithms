#include <iostream>
using namespace std;

#define SIZE 4


void printMaze(int maze[SIZE][SIZE]){
    for(int i = 0; i<SIZE; i++){
        for(int j=0 ; j<SIZE ;j++){
            cout << maze[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveMaze(int maze[SIZE][SIZE], int x, int y , int destX, int destY){
    // base Condition : reached destination
    
    if(x==destX && y == destY){
        maze[x][y] = 2; // destination mark 2 
        return true;
    }
    
    // check if position is valid
    
    if(x>=0 && x<SIZE && y>=0 && y<SIZE && maze[x][y]==1){
        // mark current path with 2
        maze[x][y] = 2;
        
        // try right
        if(solveMaze(maze , x, y+1 , destX , destY)){
            return true;
        }
        // try left
        if(solveMaze(maze , x, y-1 , destX , destY)){
            return true;
        }
        //try down
        if(solveMaze(maze , x+1, y , destX , destY)){
            return true;
        }
        // try up
        if(solveMaze(maze , x-1, y , destX , destY)){
            return true;
        }
        
        // if no direction works 
        maze[x][y] = 1;
    }
    
    return false;
    
    
    
}

int main() {
    
    int maze[SIZE][SIZE] = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1},    
    
    };
    
    cout<<"Original Maze"<< endl;
    printMaze(maze);
    cout<<endl;
    
    if(solveMaze(maze, 0,0 ,3,3)){
        cout<<"Solution found"<<endl;
        printMaze(maze);
    }
    
    else{
        cout<<"No solution"<<endl;
    }
    
    
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

void markIsland(vector<vector<int>> &grid, int x, int y, int row, int col){
    if(x<0 || y<0 || x>row || y>col || grid[x][y]!=1){
        return;
    }else{
        grid[x][y] = 2; //marking as visited, 2 represents marked

        //DFS calling starts
        //only top, bottom, left and right
        //won't work diagonally
        markIsland(grid, x-1, y, row, col);
        markIsland(grid, x+1, y, row, col);
        markIsland(grid, x, y+1, row, col);
        markIsland(grid, x, y-1, row, col);

    }
}

int numberOfIsland(vector<vector<int>> &grid){
    int numIslands = 0;
    int nRows, nCols;
    nRows = grid.size();
    nCols = grid[0].size();

    if(nRows == 0) return -1;

    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            if(grid[i][j] == 1){
                markIsland(grid, i, j, nRows, nCols);
                numIslands++;
            }
        }
    }

    return numIslands;
}

int main(){
    cout<<"Enter the number of vertices: ";
    int n;
    cin>>n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout<<"Enter 1's for land, 0's for water"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }

    int islands = numberOfIsland(grid);

    cout<<"The number of islands is: "<<islands<<endl;
}

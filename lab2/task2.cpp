#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int row, int col) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] != 0) {
        return;
    }

    grid[row][col] = 1;

    // Perform DFS in all four directions
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}

int closedIsland(vector<vector<int>>& grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    // Mark the boundary cells as visited (water)
    for (int i = 0; i < numRows; i++) {
        dfs(grid, i, 0);
        dfs(grid, i, numCols - 1);
    }

    for (int j = 0; j < numCols; j++) {
        dfs(grid, 0, j);
        dfs(grid, numRows - 1, j);
    }

    int count = 0;

    // Count the number of closed islands
    for (int i = 1; i < numRows - 1; i++) {
        for (int j = 1; j < numCols - 1; j++) {
            if (grid[i][j] == 0) {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };

    int numClosedIslands = closedIsland(grid);
    cout << "Number of closed islands: " << numClosedIslands << endl;

    return 0;
}

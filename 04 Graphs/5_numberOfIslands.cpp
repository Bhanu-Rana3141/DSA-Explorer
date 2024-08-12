#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m) {

    vis[row][col] = 1;

    if(row-1 >= 0 && !vis[row-1][col] && grid[row-1][col] == '1') {
        dfs(row-1, col, vis, grid, n, m);
    }

    if(row+1 < n && !vis[row+1][col] && grid[row+1][col] == '1') {
        dfs(row+1, col, vis, grid, n ,m);
    }

    if(col-1 >= 0 && !vis[row][col-1] && grid[row][col-1] == '1') {
        dfs(row, col-1, vis, grid, n, m);
    }

    if(col+1 < m && !vis[row][col+1] && grid[row][col+1] == '1') {
        dfs(row, col+1, vis, grid, n, m);
    }

    if(row - 1 >= 0 && col - 1 >= 0 && grid[row-1][col-1] == '1' && !vis[row-1][col-1]) {
        dfs(row-1, col-1, vis, grid, n, m);
    }
        
    // left down diagonal
    if(row + 1 < n && col - 1 >= 0 && grid[row+1][col-1] == '1' && !vis[row+1][col-1]) {
        dfs(row+1, col-1, vis, grid, n, m);
    }
        
    // right up diagonal
    if(row - 1 >= 0 && col + 1 >= 0 && grid[row-1][col+1] == '1' && !vis[row-1][col+1]) {
        dfs(row-1, col+1, vis, grid, n, m);
    }
        
    // right down diagonal
    if(row + 1 < n && col + 1 < m && grid[row + 1][col+1] == '1' && !vis[row + 1][col+1]) {
        dfs(row+1, col+1, vis, grid, n, m);
    }        
}

void dfs_2(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m) {

    vis[row][col] = 1;

    for(int delRow = -1; delRow<=1; delRow++) {
        for(int delCol = -1; delCol<=1; delCol++) {

            int nRow = row + delRow;
            int nCol = col + delCol;

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == '1') {
                dfs_2(nRow, nCol, vis, grid, n, m);
            }
        }
    }
}

void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {

    queue<pair<int,int>> q;
    q.push({row, col});
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()) {

        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // visit neighbouring vertices

        // up
        if(row - 1 >= 0 && grid[row-1][col] == '1' && !vis[row-1][col]) {
            q.push({row-1, col});
            vis[row-1][col] = 1;
        }
            
        // down
        if(row + 1 < n && grid[row+1][col] == '1' && !vis[row+1][col]) {
            q.push({row+1, col});
            vis[row+1][col] = 1;
        }
            
        // left
        if(col - 1 >= 0 && grid[row][col-1] == '1' && !vis[row][col-1]) {
            q.push({row, col-1});
            vis[row][col-1] = 1;
        }
            
            // right
        if(col + 1 < m && grid[row][col+1] == '1' && !vis[row][col+1]) {
            q.push({row, col+1});
            vis[row][col+1] = 1;
        }
            
        // left up diagonal
        if(row - 1 >= 0 && col - 1 >= 0 && grid[row-1][col-1] == '1' && !vis[row-1][col-1]) {
            q.push({row-1, col-1});
            vis[row-1][col-1] = 1;
        }
            
        // left down diagonal
        if(row + 1 < n && col - 1 >= 0 && grid[row+1][col-1] == '1' && !vis[row+1][col-1]) {
            q.push({row+1, col-1});
            vis[row+1][col-1] = 1;
        }
            
        // right up diagonal
        if(row - 1 >= 0 && col + 1 >= 0 && grid[row-1][col+1] == '1' && !vis[row-1][col+1]) {
            q.push({row-1, col+1});
            vis[row-1][col+1] = 1;
        }
            
        // right down diagonal
        if(row + 1 < n && col + 1 < m && grid[row + 1][col+1] == '1' && !vis[row + 1][col+1]) {
            q.push({row + 1, col+1});
            vis[row + 1][col+1] = 1;
        }
    }
}

void bfs_2(int row, int col, vector<vector<int>>& vis, vector<vector<char>> grid) {

    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // neighbours
        for(int delRow = -1; delRow<=1; delRow++) {
            for(int delCol = -1; delCol<=1; delCol++) {

                int nRow = row + delRow;
                int nCol = col + delCol;

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == '1') {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
}

int main() {

    int n = 2;
    int m = 7;
    vector<vector<char>> grid = {{'0', '1', '1', '1', '0', '0', '0'}, {'0', '0', '1', '1', '0', '1', '0'}};
    
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int row = 0; row<n; row++) {
        for(int col = 0; col<m; col++) {
            if(!vis[row][col] && grid[row][col] == '1') {
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }

    cout << "Total islands: " << cnt;
   
    return 0;
}
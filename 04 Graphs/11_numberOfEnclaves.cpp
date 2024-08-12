#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int delRow[], int delCol[]) {

    vis[row][col] = 1;
    
    for(int i = 0; i<4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
            dfs(nRow, nCol, grid, vis, n, m, delRow, delCol);
        } 
    }
}

int totalEnclaves(vector<vector<int>>& grid, int n, int m) {

    vector<vector<int>>vis(n, vector<int>(m , 0));
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    // check for boundary rows
    for(int col = 0; col < m; col++) {
        if(grid[0][col] == 1 && !vis[0][col]) {
            dfs(0, col, grid, vis, n, m, delRow, delCol);
        }
        if(grid[n-1][col] == 1 && !vis[n-1][col]) {
            dfs(n-1, col, grid, vis, n, m, delRow, delCol);
        }
    }

    // check for boundary columns
    for(int row = 0; row < n; row++) {
        if(grid[row][0] == 1 && !vis[row][0]) {
            dfs(row, 0, grid, vis, n, m, delRow, delCol);
        }
        if(grid[row][m-1] == 1 && !vis[row][m-1]) {
            dfs(row, m-1, grid, vis, n, m, delRow, delCol);
        }
    }

    int cnt = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int m;
    cout << "Enter m: ";
    cin >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int totalCnt = totalEnclaves(grid, n , m);
    cout << "cnt : " << totalCnt;

    return 0;
}
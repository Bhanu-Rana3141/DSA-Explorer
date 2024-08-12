#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>>& mat,  vector<vector<int>>& vis, int delRow[], int delCol[], int n, int m) {

    vis[row][col] = 1;
    for(int i = 0; i<4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 'O') {
            dfs(nRow, nCol, mat, vis, delRow, delCol, n, m);
        } 
    }
}

int main()
{
    int n = 5;
    int  m = 4;

    vector<vector<char>> mat = {{'X' , 'X' , 'X' , 'X'}, {'X' , 'O' , 'X' , 'X'} , {'X','O','O','X'}, {'X' , 'O' , 'X' , 'X'} , {'X' , 'X' , 'O' , 'O'}};
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // check for boundaries
    // first row - last row
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int col = 0; col<m; col++) {
        if(mat[0][col] == 'O' && !vis[0][col]) {
            dfs(0, col, mat, vis, delRow, delCol, n, m);
        }
        if(mat[n-1][col] == 'O' && !vis[n-1][col]) {
            dfs(n-1, col, mat, vis, delRow, delCol, n, m);
        }
    }

    for(int row = 0; row<n; row++) {
        if(mat[row][0] == 'O' && !vis[row][0]) {
            dfs(row, 0, mat, vis, delRow, delCol, n, m);
        }
        if(mat[row][m-1] == 'O' && !vis[row][m-1]) {
            dfs(row, m-1, mat, vis, delRow, delCol, n, m);
        }
    }

    // traverse in matrix and find O , check if it is visited in vis matrix if yes then this cannot be converted into X , else it will be converted into X
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(mat[i][j] == 'O' && !vis[i][j]) {
                mat[i][j] = 'X';
            }
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
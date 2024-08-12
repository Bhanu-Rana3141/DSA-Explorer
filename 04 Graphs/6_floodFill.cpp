#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& image, int newColor, int oldColor, int delRow[], int delCol[], int n, int m) {

    image[row][col] = newColor;

    for(int i = 0; i<4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == oldColor) {
            dfs(nRow, nCol, image, newColor, oldColor, delRow, delCol, n, m);
        }
    }
}

// without using visited vector, and using concept of delRow , delCol
void bfs_2(int row, int col, vector<vector<int>>& image, int newColor, int oldColor) {

    int n = 3;
    int m = 3;
    queue<pair<int, int>> q;
    q.push({row, col});
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == oldColor) {
                image[nRow][nCol] = newColor;
                q.push({nRow, nCol});
            }
        }
    }
}

void bfs(int row, int col, vector<vector<int>>& image, int& newColor, int& oldColor) {

    int n = 3;
    int m = 3;
    queue<pair<int, int>> q;
    q.push({row, col});
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[row][col] = 1;

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // up
        if(row - 1 >= 0 && !vis[row-1][col] && image[row-1][col] == oldColor) {
            vis[row-1][col] = 1;
            q.push({row-1, col});
            image[row-1][col] = newColor;
        }

        // down
        if(row + 1 < n && !vis[row+1][col] && image[row+1][col] == oldColor) {
            vis[row+1][col] = newColor;
            q.push({row+1, col});
            image[row+1][col] = newColor; 
        }

        // left
        if(col - 1 >= 0 && !vis[row][col-1] && image[row][col-1] == oldColor) {
            vis[row][col-1] = 1;
            q.push({row, col-1});
            image[row][col-1] = newColor;
        }

        // right
        if(col + 1 < m && !vis[row][col+1] && image[row][col+1] == oldColor) {
            vis[row][col+1] = 1;
            q.push({row, col+1});
            image[row][col+1] = newColor;
        }
    }
}

int main() {

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0 ,1}};
    int n = 3;
    int m = 3;
    int sr = 1;
    int sc = 1;
    int newColor = 2;

    // EDGE CASE - if oldcolor and newColor is same , return 
    if(image[sr][sc] == newColor) {
        cout << "can' t change ";
        return 0;
    }

    int oldColor = image[sr][sc];
    image[sr][sc] = newColor;

    // bfs(sr, sc, image, newColor, oldColor);
    // bfs_2(sr, sc, image, newColor, oldColor);

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    dfs(sr, sc, image, newColor, oldColor, delRow, delCol, n, m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
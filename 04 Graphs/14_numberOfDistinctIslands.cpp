#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid, int n, int m, int baseRow, int baseCol, vector<vector<int>>& vis, vector<pair<int , int>>& vec, int delRow[] , int delCol[]) {

    vis[row][col] = 1;
    vec.push_back({row - baseRow , col - baseCol});

    for(int i = 0; i<4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
            dfs(nRow, nCol, grid, n, m, baseRow, baseCol, vis, vec, delRow, delCol);
        }
    }
}

int main()
{   
    int n = 4;
    int m = 5;
    
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};

    set<vector<pair<int , int>>> st;    
    vector<vector<int>> vis(n , vector<int>(m , 0));
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            vector<pair<int , int>> vec;
            if(grid[i][j] == 1 && !vis[i][j]) {
                dfs(i, j, grid, n, m, i, j, vis, vec, delRow, delCol);
                st.insert(vec);
            }
        }
    }

    for(auto it : st) {
        cout << " { ";
        for(auto i : it) {
            cout << "(" << i.first << " , " << i.second << ") ";
        }
        cout << " } " << endl;
    }
    cout << st.size();
    
    return 0;
}
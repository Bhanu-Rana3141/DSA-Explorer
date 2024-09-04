#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// TC & SC- O(N^M)

int shortestPath(vector<vector<int>>& grid, int n, int m) {

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 1;

    if(n == 1 && grid[0][0] == 0) return 1;
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

    queue<pair<int, pair<int,int>>> q;
    q.push({1, {0,0}});

    while(!q.empty()) {
        auto it  = q.front();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        q.pop();

        for(int delRow = -1; delRow<=1; delRow++) {
            for(int delCol = -1; delCol<=1; delCol++) {
                int nRow = row + delRow;
                int nCol = col + delCol;

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0 && dis + 1 < dist[nRow][nCol]) {
                    dist[nRow][nCol] = dis + 1;
                    if(nRow == n-1 && nCol == n-1) return dis + 1;
                    q.push({dis + 1, {nRow, nCol}});
                }
            }
        } 
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    int n = grid.size();
    int m = grid[0].size();

    cout << shortestPath(grid, n, m);

    return 0;
}
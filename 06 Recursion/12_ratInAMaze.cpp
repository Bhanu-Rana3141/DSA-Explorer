#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(4^(n^2)), SC - O(N^2) for visited array and recursive call stack

void findPaths(int row, int col, vector<vector<int>>& arr, int n, vector<string>& paths, string path, vector<vector<int>>& vis, int delRow[], int delCol[], string directions[]) {

    if(row == n-1 && col == n-1) {
        paths.push_back(path);
        return;
    }

    vis[row][col] = 1;

    for(int i = 0; i < 4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        string dir = directions[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && !vis[nRow][nCol] && arr[nRow][nCol] == 1) {
            findPaths(nRow, nCol, arr, n, paths, path + dir, vis, delRow, delCol, directions);
        }
    }

    vis[row][col] = 0;
}

int main()
{   
    int n = 4;
    vector<vector<int>> arr = {{1, 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> paths;
    string path = "";
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};
    string directions[] = {"U", "R", "D", "L"};
    vector<vector<int>> vis(n, vector<int>(n, 0));

    findPaths(0, 0, arr, n, paths, path, vis, delRow, delCol, directions);

    for(auto it : paths) {
        cout << it << " ";
    }

    return 0;
}
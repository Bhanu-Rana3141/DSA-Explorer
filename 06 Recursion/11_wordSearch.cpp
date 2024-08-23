/*
TC - 
O(n × m × 4L) 
4L -> L is length of the word, maximum recursive depth for each call , in worst case it can explore all the 4 paths 

SC - O(N*M + L) 
N*M -> visited array
L - recursive call stack
*/


#include<iostream>
#include<vector>
using namespace std;

bool wordSearch(vector<vector<char>>& board, int row, int col, int& n ,int& m, vector<vector<int>>& vis, string& word, int idx, int delRow[], int delCol[]) {

    if(idx == word.size()) return true;

    vis[row][col] = 1;

    for(int i = 0; i < 4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && board[nRow][nCol] == word[idx]) {
            if(wordSearch(board, nRow, nCol, n, m, vis, word, idx+1, delRow, delCol)) return true;
        }
    }
    
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == word[0]) {
                if(wordSearch(board, i, j, n, m, vis, word, 1, delRow, delCol)) {
                    cout << "true";
                    return 0;
                }
            }
        }
    }

    cout << "false";

    return 0;
}
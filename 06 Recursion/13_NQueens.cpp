#include<iostream>
#include<vector>
using namespace std;

// TC - O(N!) && SC - O(N^2)

void addSolution(vector<vector<char>>& board, int n, vector<vector<string>>& ans) {

    vector<string> temp;
    for(int i = 0; i<n; i++) {
        string output = "";
        for(int j = 0; j<n; j++) {
            output += board[i][j];
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<char>>& board, int n) {

    int x = row;
    int y = col;

    // left row
    while(col >= 0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        col--;
    }

    row = x;
    col = y;
    // upper left diagonal
    while(row >= 0 && col >= 0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    // bottom left diagonal
    while(row < n && col >= 0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }
    return true;

    //  Q are placed from left to right , No need to check right part
}

void solve(int col, vector<vector<char>>& board, int n, vector<vector<string>>& ans) {

    if(col == n) {
        addSolution(board, n, ans);
        return;
    }

    for(int row = 0; row<n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, n, ans);
            board[row][col] = '.';
        }
    }
}

void print(vector<vector<string>>& ans) {

    for(auto it : ans) {
        cout << "[";
        for(auto i : it) {
            cout << i << ", ";
        }
        cout << "] ";
    }
}

int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    int col = 0;

    vector<vector<string>> ans;
    solve(col, board, n, ans);
    print(ans);
    
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int checkRow(vector<int>& arr, int m, int col) {
    
    for(int i = 0; i<m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = col; i<m; i++) {
        if(arr[i] == 1) {
            return 1;
        }
    }
    return 0;
}

int checkCol(vector<vector<int>>& arr, int row, int col, int n) {

    for(int i = row; i<n; i++) {
        if(arr[i][col] == 1) {
            return 1;
        }
    }
    return 0;
}

int removeStones(vector<vector<int>>& stones) {
    
    int n = stones.size();
    int m = stones[0].size();

    if(n == 1) return 0;

    int cnt = 0;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    
    for(auto it : stones) {
        int i = it[0];
        int j = it[1];

        arr[i][j] = 1;
    }
    
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(arr[i][j] == 1) {
                    if(checkRow(arr[i], m, j)) {
                        arr[i][j] = 0;
                        cnt++;
                    }
                }
                else {
                    if(checkCol(arr, i, j, n)) {
                        arr[i][j] = 0;
                        cnt++;
                    }
                }
            }
        }
    }

    return cnt;
}

int main()
{

    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};

    cout << "Removed stones: " << removeStones(stones) << endl;

    return 0;   
}
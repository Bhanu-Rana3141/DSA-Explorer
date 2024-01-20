/*
APPROACH 1 - BRUTE
* Traversing through matrix and checking for 0, TC - O(N*M)
* if 0 is found at any index, placing -1 in that entire row except that position, and same for col, TC - O(N+M)
* After placing -1, traverse again and replace -1 with 0, TC - O(N*M)
OVERALL TC - O(N*M)*O(N+M) + O(N*M)


APPROACH 2 - BETTER
* Create two arrays one for mapping rows and other for cols and initialise with 0, TC - O(N*M)
* Traverse through array and check 0, if 0 is found upadate 0 by 1 in col and row array , TC - O(N*M)
* Now again traverse through array, and apply condition if(row[i] == 1 || col[j] == 1), if this condition becomes true place 0 at that position
* OVERALL TC - O(N*M) + O(N*M) - O(2 N*M) = O(N*M)
* SC - CREATING ROW - O(M) and COL - O(N)
OVERALL SC - O(M) + O(N)
*/

#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>>& matrix) {

    cout << endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void row(vector<vector<int>>& arr, int row, int col, int n) {
    for(int i=0; i<n; i++) {
        if(arr[row][col] != 0) {
            arr[row][col] = -1;
        }
        col++;
    }
}

void col(vector<vector<int>>& arr, int row,int col, int m) {
    for(int i=0; i<m; i++) {
        if(arr[row][col] != 0) {
            arr[row][col] = -1;
        }
        row++;
    }
}

int main() {

    int m;
    cout << "Enter m: ";
    cin >> m;

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>>arr(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

/* BRUTE 
    // TC - O(N*M)*O(N+M)
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 0) {
                row(arr, i, 0, n);
                col(arr, 0, j, m);
            }
        }
    }

    // TC - O(N*M)
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == -1) {
                arr[i][j] = 0;
            } 
        }
    }
    printMatrix(arr);
*/

/* BETTER   

   vector<int> row(m, 0);
   vector<int> col(n, 0);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
   } 

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(row[i] == 1 || col[j] == 1) {
                arr[i][j] = 0;
            }
        }
    }

    printMatrix(arr);
*/  
   
   
   
    return 0;
}
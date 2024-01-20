/*
APPROACH 1 
* Creating extra array, and storing elements in 90 degree 
TC - O(N*M)
SC -  O(N*M)

APPROACH 2 
* Transpose of a matrix
* reverse each row
TC - O(N*M)
SC - 0(1)
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

void reverse(vector<int>& arr) {
    
    int i = 0;
    int j = arr.size()-1;

    while(i < j) {
        swap(arr[i], arr[j]);
        i++, j--;
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

/* BRUTE
    vector<vector<int>> matrix(n, vector<int>(n));

    for(int col=0; col<n; col++) {
        int rowIndex = col;
        int colIndex = 0;
        for(int row=n-1; row>=0; row--) {
            matrix[rowIndex][colIndex] = arr[row][col];
            colIndex++;
        }
    }

    printMatrix(matrix);
 */   
    
    // OPTIMAL
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i=0; i<n; i++) {
        reverse(arr[i]);
    }

    printMatrix(arr);
    
    return 0;
}
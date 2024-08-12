#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter no of nodes: ";
    cin >> n;

    int m;
    cout << "Enter no of edges: ";
    cin >> m;

    // SC - O(N^2)
    int adjMatrix[n+1][n+1] = {0}; // if nodes starts from 1

    for(int i=0; i<m; i++) {
        int u , v;
        cin >> u >> v;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<n+1; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
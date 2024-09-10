#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
TC 
- O(N*M) - pq will process n*m elements
- O(log (N*M)) - pq.push , pq.pop for n*m elements
- O(4 * N*M) - checking 4 neighbours for n*m elements

- O(N*M) * (log(N*M))

SC - 
- O(N*M) - PQ
- O(N*M) - dis 

*/

int minEffort(vector<vector<int>>& heights, int n, int m) {

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    pq.push({0, {0, 0}});
    dis[0][0] = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if(row == n-1 && col == m-1) return diff;

        for(int i = 0; i<4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int newEffort = max(abs(heights[row][col] - heights[nr][nc]), diff);
                if(newEffort < dis[nr][nc]) {
                    dis[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
    }
    return 0;
}

int main()
{ 
    int n = 3;
    int m = 3;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};

    cout << "min Effort : " << minEffort(heights, n, m);

    return 0;
}
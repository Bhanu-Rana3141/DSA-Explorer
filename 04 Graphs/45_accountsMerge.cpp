#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class DisjointSet {
public: 
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
    }

    int ulPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = ulPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int upu = ulPar(u);        
        int upv = ulPar(v);        

        if(upu == upv) return;

        if(rank[upu] < rank[upv]) {
            parent[upu] = upv;
        }
        else if(rank[upv] < rank[upu]) {
            parent[upv] = upu;
        }
        else {
            parent[upv] = upu;
            rank[upu]++;
        }
    }
};

vector<vector<string>> mergeAccounts(vector<vector<string>>& accounts) {

    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string, int> mpp;

    // unorderd map and union
    for(int i = 0; i<n; i++) {
        for(int j = 1; j<accounts[i].size(); j++) {
            string mail = accounts[i][j];
            if(mpp.find(mail) == mpp.end()) {
                mpp[mail] = i;
            }
            else {
                ds.unionByRank(i, mpp[mail]);
            }
        }
    }

    // merge nodes
    vector<vector<string>> mergeMail(n);
    for(auto it : mpp) {
        string mail = it.first;
        int node = ds.ulPar(it.second);
        mergeMail[node].push_back(mail);
    }

    // rearrange in sorted order
    vector<vector<string>> ans;
    for(int i = 0; i<n; i++) {
        if(mergeMail[i].size() == 0) continue;
        sort(mergeMail[i].begin(), mergeMail[i].end());

        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it : mergeMail[i]) {
            temp.push_back(it);
        }

        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};

    vector<vector<string>> ans = mergeAccounts(accounts);
    
    for(auto it : accounts) {
        for(auto i : it) {
            cout << i << " "; 
        }
        cout << endl;
    }

    return 0;
}
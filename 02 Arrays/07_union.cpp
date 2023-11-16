#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr1(n);
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter m: ";
    cin >> m;

    vector<int>arr2(m);
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }

/*
    Approach 1(brute) 

    OVERALL TC -> O(n+m) * log(n*m)

    TC ->O(n*m)
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr1[i] == arr2[j]) {
                arr2[j] = 'a';
            }
        }
    }

    TC-> O(n)
    vector<int>ans;
    for(int i=0; i<n; i++){
        ans.push_back(arr1[i]);
    }

    TC-> O(m)
    for(int i=0; i<m; i++) {
        if(arr2[i] != 'a') {
            ans.push_back(arr2[i]);
        }
    }

    TC-> O(n+m) * log(n+m)   
    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
*/
    return 0;
}
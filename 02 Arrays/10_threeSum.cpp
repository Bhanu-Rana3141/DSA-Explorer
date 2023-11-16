#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> triplet(vector<int> &arr, int n) {

    set<vector<int>> st; // to store unique triplets
     
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];    
    }

    vector<vector<int>> ans = triplet(arr,n);

    for (auto it : ans) {
            cout << "[";
            for (auto i : it) {
                cout << i << " ";
            }
            cout << "] ";
        }
        cout << "\n";

    
    return 0;
}

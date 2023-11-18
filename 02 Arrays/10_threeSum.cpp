#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/* BRUTE 
vector<vector<int>> triplet(vector<int>& arr, int n){

    set<vector<int>> st;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int>temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }   
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
*/

vector<vector<int>> triplet(vector<int>& arr, int n) {

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) {
        // skipping duplicates
        if(i>0 && arr[i] == arr[i-1]) continue;

        // moving 2 pointers
        int j = i+1;
        int k = n-1;

        while(j<k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum > 0) {
                k--;
            }
            else if(sum < 0) {
                j++;
            }
            else{
                vector<int>temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++, k--;

                // skipping duplicates
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }    
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

    
    vector<vector<int>> ans = triplet(arr, n);

    for(auto i : ans) {
        cout << "[";
        for(auto it : i) {
            cout << it << " "; 
        }
        cout << ']';
    }


    return 0;
}
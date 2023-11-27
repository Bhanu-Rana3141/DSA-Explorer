#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*BRUTE APPROCH -> NESTED LOOPS
vector<vector<int>> fourSum(vector<int>&arr, int n, int target) {
    set<vector<int>>st; //to store unique quads
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                for(int l=k+1; l<n; l++) {
                    int sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target) {
                        vector<int>temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}
*/

// OPTIMISED APPROACH -> TWO POINTER
vector<vector<int>> fourSum(vector<int>&arr, int n, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>>ans; // to store quads

    for(int i=0; i<n; i++) {
        if(i > 0 && arr[i] < arr[i-1]) {
            continue;
        }
        for(int j=i+1; j<n; j++) {
            if(j > i+1 && arr[j] == arr[j-1]) {
                continue;
            }
            int k = j+1;
            int l = n-1;

            while(k<l) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];

                if(sum == target) {
                    vector<int>temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while(k < l && arr[k] == arr[k-1]) {
                        k++;
                    }
                    while(k < l && arr[l] == arr[l+1]) {
                        l--;
                    }
                }
                else if(sum > target) {
                    l--;
                }
                else {
                    k++;
                }
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>>ans = fourSum(arr, n, target);

    for(auto it : ans) {
        cout << '[';
        for(auto i : it) {
            cout << i << " ";
        }
        cout << ']';
    }

    return 0;
}
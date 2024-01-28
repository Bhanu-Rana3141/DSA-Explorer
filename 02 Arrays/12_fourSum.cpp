/*
BRUTE APPROACH

* TC: O(N4), where N = size of the array.
Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we are just sorting 4 elements every time.
* SC: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.


OPIMISED APPROACH

* TC: O(N3) + O(N LOG N), where N = size of the array.
Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 

* SC: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/

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
                    vector<int>temp = {arr[i], arr[j], arr[k], arr[l]}; // each times 4 elements are pushed in temp , so this will take CONSTANT SPACE
                    ans.push_back(temp); // ans will take SC - O(no of quadruplets)
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
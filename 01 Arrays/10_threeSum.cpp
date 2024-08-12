/*
BRUTE - using nested loops

* TC: O(N3 * log(no. of unique triplets)), where N = size of the array.
  Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

* SC: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.


OPTIMISED
* SORTING - O(N LOG N)
* 2 LOOPS - O(N^2), WHILE LOOPS FOR AVODING DUPLICATES WILL ALSO BE COUNTED IN IT
* OVERALL - O(N^2)

* SC: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).


*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// BRUTE 
/*
vector<vector<int>> triplet(vector<int>& arr, int n){

    set<vector<int>> st;    //SC -> O(no of unique triplets)

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int>temp = {arr[i], arr[j], arr[k]}; 
                    sort(temp.begin(), temp.end()); // constant sorting 3 elements each time
                    st.insert(temp); // TC -> O(log n)
                }
            }
        }
    }   
    vector<vector<int>> ans(st.begin(), st.end()); //SC -> O(no of unique triplets)
    return ans;
}
*/

vector<vector<int>> triplet(vector<int>& arr, int n) {

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) {
        // skipping duplicates
        if(i>0 && arr[i] == arr[i-1]) {
            continue;
        }

        // moving 2 pointers
        int j = i+1;
        int k = n-1;

        while(j < k) {
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
                while(j<k && arr[j] == arr[j-1]) {
                    j++;
                } 
                while(j<k && arr[k] == arr[k+1]) {
                    k--;
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
/*
APPROACH 1 -> USING EXTRA ARRAY
OVERALL TC -> O(n)+O(n) -> O(n)
Space Complexity  -> O(n) -> because ans vector is created which will have n values

Approach 2 -> 2 POINTERS 
TC -> O(n)
SC -> O(1)

*/

#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }   

/*  vector<int>ans; 

    // TC -> O(n)
    int zeroCount = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            zeroCount++;
        }
        else{
            ans.push_back(arr[i]);
        }
    }

    // TC -> O(zeroCount) but in worst case array can have 0 at all places, in that case n traversals will be done and TC->O(n)
    for(int i=0; i<zeroCount; i++) {
        ans.push_back(0);
    }

    // TC -> O(ans.size()) but in worst case array can have n values, TC -> O(n)
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
*/

    int j=0;
    for(int i=0; i<n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
/*
APPROACH 1 - LINEAR
TC - O(N)
SC - O(1)

APPROACH 2 - BINARY SEARCH 
TC - O(N LOG N)

APPROACH 3 - INBUILT FUNCTION
* int ans = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
* arr.begin(): This returns an iterator pointing to the beginning of the array.
* arr.end(): This returns an iterator pointing to the end of the array.
* lower_bound(arr.begin(), arr.end(), x): This function finds the lower bound of the value x in the sorted range [arr.begin(), arr.end()). It returns an iterator pointing to the first element that is not less than x.
TC - O(LOG N)
SC - O(1)

*/

#include<iostream>
#include<vector>
using namespace std;

int lowerBound_1(vector<int> arr, int n, int x) {

    int ans = n;

    for(int i=0; i<n; i++) {
        if(arr[i] >= x) {
            return i;
        }
    }
    return ans;
}

int lowerBound_2(vector<int> arr, int n, int x) {

    int s = 0;
    int e = arr.size() - 1;
    int ans = n;

    while(s <= e) {

        int mid = s + (e - s) / 2;

        if(arr[mid] >= x) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    } 
    return ans;
}

int lowerBound_3(vector<int> arr, int n, int x) {

    int ans = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    return ans;
}

int main() {

    int n = 6;
    
    vector<int> arr = {1, 2, 2, 3, 3, 5};
    int x = 2;

    // int ans = lowerBound_1(arr, n, x);
    // int ans = lowerBound_2(arr, n, x);
    int ans = lowerBound_3(arr, n, x);

    cout << "lower bound : " << ans;
    
    return 0;
}
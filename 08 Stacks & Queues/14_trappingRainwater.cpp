#include<iostream>
#include<vector>
using namespace std;

int waterTrapped_1(vector<int>& arr, int n) {

    int prefix[n], suffix[n];

    prefix[0] = 0;
    for(int i = 1; i<n; i++) {
        prefix[i] = max(prefix[i-1], arr[i]);
    }

    suffix[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--) {
        suffix[i] = max(suffix[i+1], arr[i]);
    }

    int total = 0;
    for(int i = 0; i < n; i++) {
        total += min(prefix[i], suffix[i]) - arr[i];
    }

    return total;
}

int waterTrapped_2(vector<int>& arr, int n) {

    int total = 0;
    int left = 0;
    int right = n-1;
    int leftMax = 0;
    int rightMax = 0;

    while(left <= right) {
        if(arr[left] <= arr[right]) {
            if(leftMax <= arr[left]) {
                leftMax = arr[left];
            }
            else {
                total += leftMax - arr[left];
            }
            left++;
        }
        else {
            if(rightMax <= arr[right]) {
                rightMax = arr[right];
            }
            else {
                total += rightMax - arr[right];
            }
            right--;
        }
    }
    return total;
}

int main()
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = arr.size();

    // int total = waterTrapped_1(arr, n);
    int total = waterTrapped_2(arr, n);

    cout << "total : " << total;

    return 0;
}
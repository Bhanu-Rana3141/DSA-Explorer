#include<iostream>
using namespace std;

int longestSubArray_1(int arr[], int n, int k) {

    int len = 0;
    for(int i = 0; i<n; i++) {
        for(int j = i; j<n; j++) {

            int sum = 0;
            for(int k = i; k<=j; k++) {
                sum += arr[k];
            }
            if(sum == k) {
                len = max(len, j-i+1);
            }
        }
    }

    return len;
}

int longestSubArray_2(int arr[], int n, int k) {

    int len = 0;
    for(int i = 0; i<n; i++) {

        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(sum == k) {
                len = max(len, j-i+1);
                // here break is not used because the next elements of subarray can be 0, which will increase the len
            }
            if(sum > k) {
                break;
            }
        }
    }

    return len;
}

// OPTIMAL SOLUTION 2 POINTERS & SLIDING WINDOW -> ONLY IF ARRAY CONTAINS POSITIVES AND ZEROES

int longestSubArray_3(int arr[], int n, int k) {

    int maxLen = 0;
    int sum = arr[0];
    int left = 0;
    int right = 0;

    // Here the first while loop will run n times, so the TC will be O(n)
    // OVERALL - O(N) + O(N) -> O(2N) -> O(N)
    while(right < n) {
        // But here it's not fixed how many time will the loop run, sometimes it can run 2 times and sometimes it may not even run 1 time, and because of which the overall TC will be O(N) instead of O(N^2)
        //  slide the window from the left until the sum is less than or equal to k
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) {
            sum += arr[right];
        }
    }

    return maxLen;
}

// The time complexity - O(N) - Outer loop runs from right = 0 to n , but the inner loop does not runs from left to n , it runs from left to right and right can be at differnce 1 2 3 , so i can say that inner loop does not runs till n everytime
int longestSubArray_4(int *arr , int n , int k) {

    int sum = 0;
    int len = 0;
    int left = 0;
    int right = 0;

    while(right < n) {
        sum += arr[right];
        if(sum == k) {
            len = max(len , right-left+1);
        }
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        right++;
    }
    return len;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    // int maxLen = longestSubArray_1(arr, n, k);
    // int maxLen = longestSubArray_2(arr, n, k);
    // int maxLen = longestSubArray_3(arr, n, k);
    int maxLen = longestSubArray_4(arr, n, k);
    
    cout << "max len : " << maxLen;

    return 0;
}  
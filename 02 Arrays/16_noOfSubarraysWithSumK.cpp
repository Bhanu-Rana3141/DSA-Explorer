#include<iostream>
using namespace std;

// BRUTE - 1 , generate all subarrays using 3 loops TC : O(n^3), SC : O(1)
// int SubarrayCount(int arr[], int n, int k) {
//     int count = 0;
//     for(int i=0; i<n; i++) {
//         for(int j=i; j<n; j++) {
//             int sum = 0; 
//             for(int k=i; k<=j; k++) {
//                sum += arr[k];
//             }
//             if(sum == k) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// BRUTE - 2 , TC : O(n^2), SC : O(1)
// int SubarrayCount(int arr[], int n, int k) {
//     int maxLength = 0;
//     for(int i=0; i<n; i++) {
//         int sum = 0;
//         int count = 0;
//         for(int j=i; j<n; j++) {
//             sum += arr[j];
//             count++;
//             if(sum > k) {
//                 break;
//             }
//             if(sum == k) {
//                 maxLength = max(maxLength, count);
//             } 
//         }
//     }
//     return maxLength;
// }

// OPTIMAL SOLUTION 2 POINTERS & SLIDING WINDOW -> ONLY IF ARRAY CONTAINS POSITIVES AND ZEROES

int SubarrayCount(int arr[], int n, int k) {

    int maxLen = 0;
    int sum = 0;
    int left = 0;
    int right = 0;

    // Here the first while loop will run n times, so the TC will be O(n)
    // OVERALL - O(N) + O(N) -> O(2N) -> O(N)
    while(right < n) {
        sum += arr[left];
        // But here it's not fixed how many time will the loop run, sometimes it can run 2 times and sometimes it may not even run 1 time, and because of which the overall TC will be O(N) instead of O(N^2)
        //  slide the window from the left until the sum is less than or equal to k
        while(sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
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

    int count = SubarrayCount(arr, n, k);
    cout << "Count: " << count;

    return 0;
}  
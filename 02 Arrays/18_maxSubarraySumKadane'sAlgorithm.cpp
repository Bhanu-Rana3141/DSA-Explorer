/*
BRUTE FORCE 
1. USE 3 LOOPS
2. USE 2 LOOPS 

OPTIMAL
USING KADANE'S ALGORITHM
Kadane's algorithm is an efficient algorithm for finding the maximum sum contiguous subarray within 
a one-dimensional array of numbers. It was proposed by Jay Kadane in 1984. The algorithm has a time 
complexity of O(n), making it a linear-time algorithm.

TC O(N)
SC O(1)
*/

#include<iostream>
using namespace std;

int maxSubarraySum(int *arr, int n) {
    
    int maxSum = 0;
    int sum = 0;

    for(int i=0; i<n; i++) {
        sum += arr[i];
        // discard the sum, if sum becomes negative
        if(sum < k) {
            sum = 0;
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int maxSum = maxSubarraySum(arr, n);
    cout << "max sum: " << maxSum;
    
    return 0;
}
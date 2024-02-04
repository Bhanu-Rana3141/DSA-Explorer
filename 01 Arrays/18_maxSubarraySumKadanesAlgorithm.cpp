/*
BRUTE FORCE - generate all subarrays and then calculate sum
1. USE 3 LOOPS
2. USE 2 LOOPS 

OPTIMAL
USING KADANE'S ALGORITHM
Kadane's algorithm is an efficient algorithm for finding the maximum sum contiguous subarray within 
a one-dimensional array of numbers. It was proposed by Jay Kadane in 1984. The algorithm has a time 
complexity of O(n), making it a linear-time algorithm.
The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum. Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

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
        if(sum < 0) {
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
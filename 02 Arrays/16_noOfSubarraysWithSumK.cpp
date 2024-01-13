/*
APPROACH 1 : using 3 loops 
TC : O(n^3)
SC : O(1)

APPROACH 2 - using 2 loops
TC : O(n^2)
SC :O(1)

*/

#include<iostream>
using namespace std;

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

int SubarrayCount(int arr[], int n, int k) {
    int count = 0;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(sum == k) {
                count++;
            }
        }
    }
    return count;
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
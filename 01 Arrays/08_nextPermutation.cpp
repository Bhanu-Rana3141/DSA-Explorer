/* APPROACHES
BRUTE FORCE -> Recursion 
1. Generate all permutations in sorted order
2. Linear search 
3. Next index will be the ans

TC -> total possible permutations n!, and array contains n no of elements so, O(n! * n) 


BETTER SOLUTION 
-> use of STL inbuilt function next_permutation(a.begin(), a.end()); the result of this will be the next permutation
TC - O(n) 
SC - O(1)

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    next_permutation(arr.begin(), arr.end());

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
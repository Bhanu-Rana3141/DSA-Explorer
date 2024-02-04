/*
Approach 1 -> SORT
* sort array and comapare index with array elements, the index which will not be equal to element of array will be the missing element
* TC : O(n log n)
* SC : O(1)

APPROACH 2 : SUM 
* calcuale sum of all the array elements 
* calculate sum of all indexes
* now, indexSum - elementSum = missing element
* TC - O(n)
* SC - O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);

    for(int i=0; i<n-1; i++) {
        cin >> arr[i];
    }  

/*  sort(arr.begin(), arr.end());

    // EDGE CASE - checking last element, because if array size is 3 then the index can be 0 1 2 so that's why last element have to be checked separately
    if(arr[n-1] != n) {
        cout << n;
        return 0;
    }

   for(int i=0; i<n-1; i++) {
        if(i != arr[i]) {
            cout << arr[i];
            return 0;
        }
    }
*/   
    
    int indexSum = (n*(n+1))/2; 
    int elementSum = 0;

    // 1 element is missing so the stopping condition will be n-1
    for(int i=0; i<n-1; i++) {
        elementSum += arr[i];
    }

    cout << "missing no: " << indexSum - elementSum;

    return 0;

}
/*
APPROACH 1 : SET
* use set and copy values from arr, as set does not store any duplicate value so all the duplicates will be removed
* TC - O(n*logn) - Iterating through all the elements of array while copying in set, and insertion operation of set takes O(log n) 
* SC - O(n) - in worst case all the elements can be unique

APPROACH 2 : 2 POINTERS
TC : O(n)
SC : O(1)
*/

#include<iostream>
#include<set>
#include<vector>
using namespace std;

/*int removeDuplicates(int arr[], int n) {

    set<int> uniqueElements;

    for(int i=0; i<n; i++) {
        uniqueElements.insert(arr[i]);
    }

    int k = 0;
    for(auto it : uniqueSet) {
        arr[k] = it;
        k++;
    }
    return k;
}
*/

int removeDuplicates(int arr[], int n) {

    int k = 1;
    int i = 1;

    while(i < n) {
        if(arr[i] == arr[i-1]) {
            i++;
        }
        else {
            arr[k] = arr[i];
            k++, i++;
        }
    }
    return k;
}

int main() {

    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int totalUnique = removeDuplicates(arr, n);
    cout << "total elements after removing duplicates: " << totalUnique << endl;

    for(int i=0; i<totalUnique; i++) {
        cout << arr[i] << " ";
    }
 
    delete []arr;
    
    return 0;
}
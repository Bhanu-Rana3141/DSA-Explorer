#include<iostream>
#include<set>
#include<vector>
using namespace std;

/*int removeDuplicates(int arr[], int n) {

    set<int> st;
    
    for(int i=0; i<n; i++) {
        st.insert(arr[i]);
    }

    for(auto it : st) {
        cout << it << " ";
    }
    cout << endl;

    int k = 0;
    int j = 0;
    for(auto it : st) {
        arr[j] = it;
        j++, k++;
    }

    for(int i=0; i<st.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return k;
}
*/

int removeDuplicates(int arr[], int n) {

    int j=0;
    for(int i=1; i<n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j+1;
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
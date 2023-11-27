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
/*  Approach 1 -> O(n log n)
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

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

    for(int i=0; i<n-1; i++) {
        elementSum += arr[i];
    }

    cout << "missing no: " << indexSum - elementSum;

    return 0;

}
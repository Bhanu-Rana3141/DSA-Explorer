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
    
    return 0;

}
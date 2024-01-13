#include<iostream>
#include<algorithm>
using namespace std;

// APPROACH 1 -> nested loops   TC -> O(n^2)    SC : O(1)
int majorityElement_1(int arr[], int n) {

    for(int i=0; i<n; i++) {
        if(arr[i] == '#') {
            continue;
        }
        int count = 1;
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = '#';
            }
        }
        if(count > (n/2)) {
            return arr[i];        
        }
    }
}


int majorityElement_2(int arr[], int n) {
    
    sort(arr, arr+n);

    return arr[n/2];
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // int ans = majorityElement_1(arr, n);

    int ans = majorityElement_2(arr, n);
    cout << "ans: " <<ans;
    
    
    return 0;
}
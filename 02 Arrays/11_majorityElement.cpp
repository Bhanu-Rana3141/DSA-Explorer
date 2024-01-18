/* 
BRUTE - frequency count
TC - O(N^2)
SC - O(1)

INBUILT SORT
TC - O(N log N)
SC - O(1)

BETTER - USING MAP -> STORING FREQUENCY OF EACH ELEMENT
TC - O(N) - FOR TRAVERSING AND O(LOG N) -> FOR USING MAP
OVERALL TC - O(N*LOG N)
SC - O(N)



*/

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

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

int majorityElement_3(int arr[], int n) {

    map<int, int> mpp;
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }
    // it.first -> points to element(key)
    // it.second -> points to frequency(value)
    for(auto it : mpp) {
        if(it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
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
    // int ans = majorityElement_2(arr, n);
    int ans = majorityElement_3(arr, n);
    cout << "ans: " << ans;
    
    
    return 0;
}
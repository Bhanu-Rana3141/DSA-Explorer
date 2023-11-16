//TC - O(N)
//SC - O(1) 


#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;
    
    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int maxOnes = 0, count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            count++;
            maxOnes = max(maxOnes, count);
        }
        else{
            count = 0;
        }
    }

    cout << "Max ones: " << maxOnes;

    return 0;
}   
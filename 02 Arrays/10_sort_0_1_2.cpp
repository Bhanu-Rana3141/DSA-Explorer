#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int> &arr){
    for(auto it : arr) {
        cout << it << " ";
    }
    cout << endl;
}

// Not inplace because of overwriting 
void sortArray(vector<int>&arr) {
    int n = arr.size();

    int zeroCount=0, oneCount=0, twoCount=0;

    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            zeroCount++;
        }
        else if(arr[i] == 1) {
            oneCount++;
        }
        else{
            twoCount++;
        }
    }
    
    int i=0;
    while(zeroCount--) {
        arr[i] = 0;
        i++;
    }
    
    while(oneCount--) {
        arr[i] = 1;
        i++;
    }

    while(twoCount--) {
        arr[i] = 2;
        i++;
    }
}

// using 3 pointers
// Dutch National Flag algorithm, which is used to sort an array containing only 0s, 1s, and 2s in a specific order. This algorithm was designed by Edsger Dijkstra and is considered an in-place sorting algorithm because it rearranges the elements within the given array without using additional memory.
void dutchNationalAlgorithm(vector<int>& arr) {

    int low = 0, mid = 0, high = arr.size()-1;
    
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++, mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // sortArray(arr);

    dutchNationalAlgorithm(arr);
    printArray(arr);


}
#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr) {

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rearrangeElement_1(vector<int>& arr, int n) {

    vector<int>positive;
    vector<int>negative;

    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }

    cout << "positive: ";
    printArray(positive);

    cout << "negative: ";
    printArray(negative);

    vector<int>ans;

    for(int i=0; i<n/2; i++) {
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
    }

    printArray(ans);
}


void rearrangeElement_2(vector<int>& arr, int n) {

    vector<int> ans(n,0);

    int posIndex = 0, negIndex = 1;

    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    printArray(ans);
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    if(arr.size() == 2) {
        swap(arr[0], arr[1]);
        cout << arr[0] << " " << arr[1];
        return 0;
    }

    // rearrangeElement_1(arr, n);

    rearrangeElement_2(arr, n);
    
    return 0;
}
#include<iostream>
#include<vector>
#include<map>

using namespace std;

void print(vector<int>&arr) {
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void majorityElement_1(vector<int>&arr) {
    // edge case
    if(arr.size() == 1) {
        cout << arr[0];
        return;
    }

    vector<int>ans;

    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == '#') {
                continue;
        }
        int count = 1;
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = '#';
            }
        }
        if(count > (arr.size()/3)){
            ans.push_back(arr[i]);
        }
    }
    print(ans);
}

void majorityElement_2(vector<int>&arr) {
    map<int,int> mpp;
    int n = arr.size();
    int min = n/3+1;

    vector<int>ans;

    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;   // in starting it will not find the value i.e value = 0 for that particular key
        if(mpp[arr[i]] == min) {
            ans.push_back(arr[i]);
        }
        if(ans.size() == n/3) { // ans can only contain maximum of n/3 elements
            break;
        }
    }
    print(ans);
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Brute Force -> nested loops
    // majorityElement_1(arr);

    // Better Approach -> Hashmap
    // majorityElement_2(arr);
    
    


}
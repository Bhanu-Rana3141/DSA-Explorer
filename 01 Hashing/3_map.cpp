/*
ORDERED MAP 
TC -> storing & fetching -> O(log n)

UNORDERED MAP 
TC ->  in most of cases storing & fetching in avg and best case will be O(1) and O(n) in worst case and return in O(N^2) due to collisions

*/

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    map<int, int> mpp;

    // pre-compute
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }

    for(auto it : mpp) {
        cout << it.first << "->" << it.second << endl;
    }

    cout << endl;

    string s;
    cout << "Enter string: ";
    cin >> s;

    map<char, int> cMpp;
    // pre-compute
    for(int i=0; i<s.size(); i++) {
        cMpp[s[i]]++;
    }

    for(auto it : cMpp) {
        cout << it.first << "->" << it.second << endl;
    }

    cout << endl;

    unordered_map<int, int> uMpp;
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr2[size];

    // overall -> O(n^2)
    for(int i=0; i<size; i++) { // O(n)
        cin >> arr2[i];
        // in worst case -> O(n)
        uMpp[arr2[i]]++;
    }

    for(auto it: uMpp) {
        cout << it.first << "->" << it.second << endl;
    }



    /* query
    int q;
    cout << "Enter q: ";
    cin >> q;

    while(q--) {
        int number;
        cin >> number;
        //fetch
        cout << mpp[number] << " ";
    }*/
    

    return 0;
}
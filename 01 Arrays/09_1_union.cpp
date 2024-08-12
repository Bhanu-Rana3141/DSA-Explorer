#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;


/* APPROACH 1  - MAP using ordered map to store keys in sorted order
TC - O(N * LOG(N)) + O(M * LOG(M)) + O(N+M)
overall -  O(N+M)*(LOG(M+N))

SC - O(N+M)
*/
vector<int> Union_1(int arr1[], int n, int arr2[], int m) {

    map<int, int> mpp;

    for(int i=0; i<n; i++) {
        mpp[arr1[i]]++;
    }

    for(int i=0; i<m; i++) {
        mpp[arr2[i]]++;
    }

    vector<int> unionArr;
    for(auto it : mpp) {
        unionArr.push_back(it.first);
    }

    return unionArr;
}

/* APPROACH 2  - SET
TC - O(N * LOG(N)) + O(M * LOG(M)) + O(N+M)
overall -  O(N+M)*(LOG(M+N))

SC - O(N+M)

*/
vector<int> Union_2(int arr1[], int n, int arr2[], int m) {

    set<int> st;

    for(int i=0; i<n; i++) {
        st.insert(arr1[i]);
    }

    for(int i=0; i<m; i++) {
        st.insert(arr2[i]);
    }

    vector<int> unionArr;
    for(auto it : st) {
        unionArr.push_back(it);
    }

    return unionArr;
}

/*
APPROACH 3 - 2 POINTER
- arr1[i] < arr2[j] , insert i and increment 
- arr1[i] == arr2[j], insert i, and increment i and j
- arr1[i] > arr2[j], insert j and increment 

while inserting element in unionArr check last element of unionArr if it is equal to element we are going to insert then its a duplicate element and don't insert it

*/
vector<int> Union_3(int arr1[], int n, int arr2[], int m) {

    vector<int> unionArr;

    int i = 0;
    int j = 0;

    while(i < n && j < m) {

        if(arr1[i] < arr2[j]) {
            if(unionArr.size() == 0) {
                unionArr.push_back(arr1[i]);
                i++;
            }
            else {
                if(arr1[i] != unionArr[unionArr.size() - 1]) {
                    unionArr.push_back(arr1[i]);
                    i++;
                }
                else {
                    i++;
                }
            }
        }
        else if(arr1[i] == arr2[j]) {
            if(unionArr.size() == 0) {
                unionArr.push_back(arr1[i]);
                i++, j++;
            }
            else {
                if(arr1[i] != unionArr[unionArr.size() - 1]) {
                    unionArr.push_back(arr1[i]);
                    i++, j++;
                }
                else {
                    i++, j++;
                }
            }
        }
        else {
            if(unionArr.size() == 0) {
                unionArr.push_back(arr2[j]);
                j++;
            }
            else {
                if(arr2[j] != unionArr[unionArr.size() - 1]) {
                    unionArr.push_back(arr2[j]);
                    j++;
                }
                else {
                    j++;
                }
            }
        }
    }

    while(i < n) {
        if(arr1[i] != unionArr[unionArr.size() - 1]) {
            unionArr.push_back(arr1[i]);
            i++;
        }
    }

    while(j < m) {
        if(arr2[j] != unionArr[unionArr.size() - 1]) {
            unionArr.push_back(arr2[j]);
            j++;
        }
    }

    return unionArr;
}

int main() {

    int n = 10;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int m = 7;
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};

    // vector<int> ans = Union_1(arr1, n, arr2, m);
    // vector<int> ans = Union_1(arr1, n, arr2, m);
    vector<int> ans = Union_1(arr1, n, arr2, m);

    for(auto it : ans) {
        cout << it << " ";
    }
    
    return 0;
}
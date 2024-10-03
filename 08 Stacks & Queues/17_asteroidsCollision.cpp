#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n = 4;
    vector<int> arr = {-2,-1,1,2};

    vector<int> ls;

    for(int i = 0; i<n; i++) {
        if(arr[i] > 0) {
            ls.push_back(arr[i]);
        }
        else {
            while(!ls.empty() && ls.back() > 0 && ls.back() < abs(arr[i])) {
                ls.pop_back();
            }
            if(!ls.empty() && ls.back() == abs(arr[i])) {
                ls.pop_back();
            }
            else if(ls.empty() || ls.back() < 0) {
                ls.push_back(arr[i]);
            }
        }
    }

    for(auto it : ls) {
        cout << it << " ";
    }

    return 0;
}
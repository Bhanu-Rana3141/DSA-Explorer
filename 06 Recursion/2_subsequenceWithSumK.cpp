#include<iostream>
#include<vector>
using namespace std;

// Q. just print only 1 subsequence whose sum == k ?

/*
bool subSequences(vector<int>& arr, int n, int k, int i, int& cnt, int sum, vector<int>& sub) {

    if(i >= n) {
        if(sum == k) {
            cnt++;
            for(auto it : sub) {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    sum += arr[i];
    sub.push_back(arr[i]);
    if(subSequences(arr, n, k, i+1, cnt, sum, sub) == true) {
        return true;
    }

    sum -= arr[i];
    sub.pop_back();
    if(subSequences(arr, n, k, i+1, cnt, sum, sub) == true) {
        return true;
    } 

    return false;
}


int main()
{
    int n = 3;
    vector<int> arr = {1,2,1};
    int k = 2;

    int sum = 0;
    int cnt = 0;
    vector<int> sub;

    subSequences(arr, n, k, 0, cnt, sum, sub);
    cout << "cnt : " << cnt;

    return 0;
}

// Q. cnt of subsequences ?
#include<iostream>
#include<vector>
using namespace std;

// Q. just print only 1 subsequence whose sum == k ?

int subSequences(vector<int>& arr, int n, int k, int i, int sum) {

    if(i >= n) {
        if(sum == k) {
           return 1;
        }
        return 0;
    }

    sum += arr[i];
    int left = subSequences(arr, n, k, i+1, sum);

    sum -= arr[i];
    int right = subSequences(arr, n, k, i+1, sum);

    return left + right;
}

int main()
{
    int n = 3;
    vector<int> arr = {1,2,1};
    int k = 2;

    int sum = 0;
    int cnt = subSequences(arr, n, k, 0, sum);
    cout << "cnt : " << cnt;

    return 0;
}

*/

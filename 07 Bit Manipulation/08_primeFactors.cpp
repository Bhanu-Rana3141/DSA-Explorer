#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> ans;
    for(int i = 2; i<=n; i++) {
        if(n % i == 0) {
            ans.push_back(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }

    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}
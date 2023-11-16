#include<iostream>
#include<string>
using namespace std;

int main() {

    string s = "abcdabehf";
    cout << s << endl;

    int hash[256] = {0};

    for(int i=0; i<s.size(); i++) {
        hash[s[i]]++;
    }

    int q;
    cout << "enter total no's for checking frequency: ";
    cin >> q;
    while(q--) {
        char ch;
        cin >> ch;

        cout << hash[ch] << " ";
    }

    return 0;
}
#include<iostream>
using namespace std;

int main() {

    string s;
    cout << "Enter s: ";
    cin >> s;

    int hash[256] = {0};
    for(int i=0; i<s.size(); i++) {
        hash[s[i]] += 1;
    }

    int q;
    cout << "Enter q: ";
    cin >> q;

    while(q--) {
        char ch;
        cin >> ch;
        cout << hash[ch] << " ";
    }

/*
    string s = "bchghskjgjffj";

    int hash[26] = {0};    // for lower case characters
    for(int i=0; i<s.size(); i++) {
        hash[s[i] - 'a'] += 1;
    }

    int q;
    cout << "Enter q: ";
    cin >> q;

    while(q--) {
        char c;
        cin >> c;

        cout << hash[c - 'a'] << " ";
    }
*/
   
   
    return 0;
}
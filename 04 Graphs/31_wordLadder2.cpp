#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

vector<vector<string>> findAllShortestPaths(string& beginWord, string& endWord, vector<string>& wordList) {

    vector<vector<string>> ans;
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    int level = 0;

    while(!q.empty()) {

        vector<string> vec = q.front();
        q.pop();

        if(vec.size() > level) {
            level++;
            for(auto it : usedOnLevel) {
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();
        if(word == endWord) {
            if(ans.size() == 0) {
                ans.push_back(vec);
            }
            else if(vec.size() == ans[0].size()) {
                ans.push_back(vec);
            }
        }

        int size = word.size();
        for(int i = 0; i < size; i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()) {
                    vec.push_back(word);
                    q.push(vec);
                    vec.pop_back();
                    usedOnLevel.push_back(word);
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

int main()
{

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> ans = findAllShortestPaths(beginWord, endWord, wordList);

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
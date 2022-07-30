#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_set<int> open;
		unordered_map<char, int> close;
		unordered_set<char> encountered;
		for(int i = 0; i < s.size(); i++){
			char c = s[i];
			if(encountered.find(c) == encountered.end()) encountered.insert(c), open.insert(i);
			close[c] = i;
		}
		int opens = 0, subseqlen = 0;
		vector<int> res;
		for(int i = 0; i < s.size(); i++){
			subseqlen++;
			if(open.find(i) != open.end()) opens++;
			if(close[s[i]] == i) opens--;
			if(opens == 0){
				res.push_back(subseqlen);
				subseqlen = 0;
			}
		}
		return res;
    }
};

int main(){
}


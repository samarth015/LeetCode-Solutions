#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
		vector<int> mp(129, 0);
		for(auto ch : s) mp[ch]++;
		unordered_set<int> uniques {};
		for(int i = 0; i < mp.size(); i++) if(mp[i] == 1) uniques.insert(i);
		for(int i = 0; i < s.size(); i++) if(uniques.find(s[i]) != uniques.end()) return i;
		return -1;
    }
};

int main(){
}


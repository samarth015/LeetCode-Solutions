#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
		unordered_map<char, int> fs, ft;
		for(auto c : s) fs[c]++;
		for(auto c : t) ft[c]++;
		for(auto f : fs) if( ft[ f.first ] != f.second ) return false;
		return true;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
		unordered_map<char, int> rf;
		for(auto c : s) rf[c]++;
		for(auto c : t) rf[c]--;
		for(auto f : rf) if( f.second != 0 ) return false;
		return true;
    }
};


class Solution3 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

int main(){
}


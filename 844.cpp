#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
		string ns, nt;
		for(auto c : s){
			if(c != '#') ns.push_back(c);
			else if(!ns.empty()) ns.pop_back();
		}
		for(auto c : s){
			if(c != '#') nt.push_back(c);
			else if(!nt.empty()) nt.pop_back();
		}
		return nt == ns;
    }
};

class Solution2 {
public:
    bool backspaceCompare(string s, string t) {
		string rs, rt;
		for(int i = s.size() - 1, cnt = 0; i >= 0; i--){
			if(s[i] == '#') cnt++;
			else if(cnt) cnt--;
			else rs.push_back(s[i]);
		}
		for(int i = t.size() - 1, cnt = 0; i >= 0; i--){
			if(t[i] == '#') cnt++;
			else if(cnt) cnt--;
			else rt.push_back(t[i]);
		}
		return rs == rt;
    }
};

// Constant space
class Solution3 {
public:
    bool backspaceCompare(string s, string t) {
		int cntS{0}, cntT{0}, i = s.size() - 1, j = t.size() - 1;
		while(i >= 0 and j >= 0){
			while(i >= 0 and (cntS or s[i] == '#')){
				if(s[i] == '#') cntS++;
				else cntS--;
				i--;
			}
			while(j >= 0 and (cntT or s[j] == '#')){
				if(s[j] == '#') cntT++;
				else cntT--;
				j--;
			}
			if(i < 0 or j < 0) break;
			if(s[i] != t[j]) return false;
			i--, j--;
		}
		return i == j;
    }
};

int main(){
}


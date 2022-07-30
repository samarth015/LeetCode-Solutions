#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
		int level = 0;
		string result;
		for(auto ch : s){
			if(level > 1 or (level == 1 and ch == '(' )) result.push_back(ch);
			if(ch == '(') level++;
			else level--;
		}
		return result;
    }
};

int main(){
}

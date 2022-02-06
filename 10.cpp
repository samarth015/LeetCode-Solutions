#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		bool charsMatch(char a, char b){
			return b == '.' or a == b;
		}
	public:
		bool isMatch(string s, string p){
			int i{}, j{};

			while(i < s.size() and j < p.size()){
				if(p[j+1] == '*'){
					while(i < s.size() and charsMatch(s[i], p[j])) i++;
					j += 2;
				}
				else{
					if(not charsMatch(s[i], p[j])) return false;
					i++; j++;
				}
			}
			return i == s.size() and j == p.size();
		}

};

int main(){
	cout << Solution{}.isMatch("aaa", "a*");
}

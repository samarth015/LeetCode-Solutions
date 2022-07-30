#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		bool ispalin(string s){
			int len = s.size();
			for(int i = 0, j = len - 1; i < j; i++, j--)
				if(s[i] != s[j]) return false;

			return true;
		}
	public:
		bool isPalindrome(string s){
			string converted_str {};
			for(char ch : s){ 
				if(std::isupper(ch)) converted_str.push_back(std::tolower(ch));
				else if(std::islower(ch) or std::isdigit(ch)) converted_str.push_back(ch);
			}
			return ispalin(converted_str);
		}
};

class Solution2 {
public:
    bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), [](unsigned char a){return std::tolower(a);});

		auto it = remove(s.begin(), s.end(), [](unsigned char c){ return not isalnum(c); });
		s.erase(it, s.end());

		int n = s.size();
		for(int i = 0; i <= n/2; i++)
			if(s[i] != s[n-i-1]) 
			
				return false;
		return true;
    }
};

int main(){
}

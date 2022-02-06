#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLastWord(string s) {
			int i = s.size() - 1;
			while(i >= 0 and s[i] == ' ') i--;
			int lastcharpos = i;
			while(i >= 0 and s[i] != ' ') i--;
			return lastcharpos - i;
		}
};

int main(){
	cout << Solution{}.lengthOfLastWord("hell no no no sdfff  ");
}

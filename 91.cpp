#include<bits/stdc++.h>
using namespace std;

class Solution3 {
public:
    int numDecodings(string s){
		int p1 = s.back() != '0', p2 = 0;

		for(int i = s.size()-2; i >= 0; i--){
			int tmp = p1;

			if(s[i] == '0')
				p1 = 0;
			else if(s[i] == '1' or s[i] == '2' and s[i+1] <= '6')
				p1 = p1 + p2;

			p2 = tmp;
		}

		return p1;
    }
};

class Solution {
	vector<int> memo;
	string s;

	int numDecodings(int i){
		if(memo[i] == -1){
			if(s[i] == '0')
				memo[i] = 0;
			else if(s[i] == '1' or s[i] == '2' and s[i+1] <= '6')
				memo[i] = numDecodings(i+1) + numDecodings(i+2);
			else
				memo[i] = numDecodings(i+1);
		}
		return memo[i];
	}

	public:
	int numDecodings(string s){
		this->s = s;
		memo = vector<int>(s.size()+1, -1);
		memo[s.size()] = 1;
		memo[s.size()-1] = s.back() != '0';

		return numDecodings(0);
	}
};

int main(){
}


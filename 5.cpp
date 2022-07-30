#include<bits/stdc++.h>
using namespace std;

// O(n^2)
class Solution3{
	int max_len, l_max, r_max, n;
	string s;

	void spreadOutToFindPalin(int l, int r){
		while(0 <= l and r < n and s[l] == s[r])
			l--, r++;
		if(r-l-1 > max_len){
			max_len = r-l-1;
			l_max = l;
			r_max = r;
		}
	}

	public:
		string longestPalindrome(string s) {
			this->s = s;
			n = s.size();
			max_len = 0;

			for(int i = 0; i < n; i++){
				spreadOutToFindPalin(i-1, i+1);
				spreadOutToFindPalin(i, i+1);
			}

			return string(s.begin()+l_max+1, s.begin()+r_max);
		}
};

// Best Case O(n) - all elements are the same
// Worst Case O(n^3)
class Solution{
	string s;

	bool isPalin(int l, int r){
		while(l < r and s[l] == s[r])
			l++, r--;
		return l >= r;
	}

	public:
		string longestPalindrome(string s) {
			this->s = s;
			int l, r;
			for(int len = s.size(); len > 1; len--){
				l = 0, r = len-1;
				while(r < s.size()){
					if(isPalin(l, r)){
						return string(s.begin()+l, s.begin()+r+1);
					}
					l++, r++;
				}
			}
			return string{s[0]};
		}
};

// Best Case O(n) - all elements are the same
// Worst Case O(n^3)
class Solution2{
	string s;

	bool isPalin(int l, int r){
		while(l < r and s[l] == s[r])
			l++, r--;
		return l >= r;
	}

	public:
		string longestPalindrome(string s) {
			this->s = s;
			int n = s.size();
			int max_l = 0, max_r = 0, max_len = 1;
			int l = 0, r;

			while(n-l > max_len){
				r = n-1;
				while(r-l+1 > max_len){
					if(isPalin(l,r)){
						max_len = r-l+1;
						max_r = r;
						max_l = l;
						break;
					}
					r--;
				}
				l++;
			}

			return string(s.begin()+max_l, s.begin()+max_r+1);
		}
};


int main(){
	cout << Solution2{}.longestPalindrome("abbcccbbbcaaccbababcbcabca");
}


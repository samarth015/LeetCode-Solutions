#include<bits/stdc++.h>
using namespace std;

// O(n^2)
class Solution2{
	string s;
	int n;

	int spreadOutToFindPalins(int l, int r){
		while(0 <= l and r < n and s[l] == s[r])
			l--, r++;
		return ceil((r-l-1)/2.0);
	}

	public:
    int countSubstrings(string s) {
			this->s = s;
			n = s.size();
			int cnt = 0;

			for(int i = 0; i < n; i++){
				cnt += spreadOutToFindPalins(i-1, i+1) + spreadOutToFindPalins(i, i+1);
			}

			return cnt;
		}
};

// Worst Case O(n^3) - When all elements of the sequence are the same
// Best Case O(n^2) - When all elements are distinct
class Solution{
	string s;

	bool isPalin(int l, int r){
		while(l < r and s[l] == s[r])
			l++, r--;
		return l >= r;
	}

	public:
		int countSubstrings(string s) {
			this->s = s;
			int res = s.size();

			int l, r;
			for(int len = s.size(); len > 1; len--){
				l = 0, r = len-1;
				while(r < s.size()){
					if(isPalin(l, r))
						res++;
					l++, r++;
				}
			}
			return res;
		}
};

int main(){
}


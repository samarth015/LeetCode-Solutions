#include<bits/stdc++.h>
using namespace std;

// Every substring has a major element( of highest frequency ) and non major elements.
// For any substring the sum of non major frequencies cannot be greater than k, since we can
// only substitute k elements.
// Create a sliding window and a table to store frequencies of all characters in the window.
// Finding sum of non majority frequency takes constant time since its all upper case english
// characters ( 26 ).

class Solution {
	private:
		vector<int> freq;
		
		int nonMajorFrequency(){
			int maxi = 0, total = 0;
			for(auto f: freq){
				if(maxi < f) maxi = f;
				total += f;
			}
			return total - maxi;
		}

public:
	Solution(): freq(26, 0) {} 

	int characterReplacement(string s, int k) {
		if(s.empty()) return 0;

		int n = s.size();
		int l = -1, r = 0, res = 0;

		while(r < n){
			int addedchar = s[r++] - 'A';
			freq[ addedchar ]++;
			while(nonMajorFrequency() > k){
				int removedchar = s[++l] - 'A';
				freq[ removedchar ]--;
			}
			res = max(res, r-l-1);
		}
		return res;
	}
};

int main(){
	 cout << Solution{}.characterReplacement("AABABBA", 1);
}

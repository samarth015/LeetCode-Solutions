#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		bool allLettersIncludedInWindow(unordered_map<char, int> &required_letters){
			return all_of(required_letters.begin(), required_letters.end(), 
					[](auto a){ return a.second <= 0; });
		}

	public:
		string minWindow(string s, string t) {
			if(s.size() < t.size()) return "";

			unordered_map<char, int> required_letters;
			for(auto c: t) required_letters[c]++;

			int l_min, r_min, l = -1, r = 0, minlen = INT_MAX, n = s.size();

			while(r < n){
				while(r < n and not allLettersIncludedInWindow(required_letters)){
					while(r < n and  required_letters.find(s[r]) == required_letters.end())
						r++;

					if(r == n) break; 
					required_letters[ s[r++] ] -= 1;
				}

				if(not allLettersIncludedInWindow(required_letters)) continue;

				do{
					while(required_letters.find(s[l+1]) == required_letters.end()) 
						l++;

					required_letters[ s[++l] ] += 1;

				} while(required_letters[ s[l] ] <= 0);

				if(minlen > r-l)
					minlen = r-l, l_min = l - 1, r_min = r;

			}

			return (minlen == INT_MAX ? "" : string( s.begin() + l_min + 1, s.begin() + r_min ));
		}
};

int main(){
}


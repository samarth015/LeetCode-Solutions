#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<int> freqdiff;
	bool windowIsPermutation(){
		return all_of(freqdiff.begin(), freqdiff.end(), 
				[](auto fd){ return fd == 0; });
	}

public:
	Solution(): freqdiff(26,0) {}

    bool checkInclusion(string s1, string s2) {
		if(s1.size() > s2.size()) return false;
		int s1len = s1.size();

		for(int i = 0; i < s1len; i += 1){
			freqdiff[ s2[i] - 'a' ] += 1;
			freqdiff[ s1[i] - 'a' ] -= 1;
		}

		int l = -1, r = s1len;
		while(r < s2.size() and not windowIsPermutation()){
			char added = s2[r++] - 'a', removed = s2[++l] - 'a';
			freqdiff[ added ] += 1;
			freqdiff[ removed ] -= 1;
		}
		return windowIsPermutation();
    }
};

int main(){
	cout << Solution{}.checkInclusion("ab", "eidboaoo");
}

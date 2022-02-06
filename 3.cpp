#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s){
			int max_len = 0, curr_len = 0, substr_beg = 0;
			int indexes[256] {-1};
			memset(indexes, -1, sizeof(indexes));
			for(int i = 0; i < s.size(); i++){
				char curr_ch = s[i];
				if(indexes[ curr_ch ] != -1){
					if(curr_len > max_len) max_len = curr_len;
					curr_len = i - indexes[ curr_ch ] - 1;
					while(substr_beg < indexes[ curr_ch ]){
						indexes[ s[substr_beg ] ] = -1;
						substr_beg++;
					}
					substr_beg++;
				}
				indexes[ curr_ch ] = i;
				curr_len++;

				/*
				for(int j = 'a'; j <= 'z'; j++) cout << indexes[j] << ' ';
				cout << endl;
				std::cout << curr_len << ' ' << max_len << ' '<< substr_beg << std::endl;
				cout << endl;
				*/	
			}
			if(curr_len > max_len) max_len = curr_len;
			return max_len;
		}
};

int main(){
	cout << Solution{}.lengthOfLongestSubstring("abba");
}

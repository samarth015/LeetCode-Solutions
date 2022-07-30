#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int l = -1, r = 0, maxlen = 0, length = s.size();
        unordered_set<char> encountered;
        while(r < length){
            cout << l << ' ' << r << endl;
            char c = s[r++];
            while(encountered.find(c) != encountered.end())
                encountered.erase(s[++l]);
            encountered.insert(c);
			maxlen = max(maxlen, r-l-1);
        }
        maxlen = max(maxlen, r-l-1);
        return maxlen;
    }
};

class Solution2 {
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
	cout << Solution2{}.lengthOfLongestSubstring("abba");
}

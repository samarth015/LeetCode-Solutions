#include<bits/stdc++.h>
using namespace std;

// Most elegant
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.empty()) return 0;
		unordered_set<int> uset (nums.begin(), nums.end());
		int maxlen = 0, currlen;
		for(auto n: uset){
			if(uset.find(n-1) != uset.end()){
				currlen = 0;
				while(uset.find(n + currlen) != uset.end())
					currlen++;
				maxlen = max(currlen, maxlen);
			}
		}
		return maxlen;
	}
};

// Clever (Unnecessarily). Stores boundary information in hash table
class Solution5 {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> umap;
		int maxlen = 0;
		for(auto n: nums){
			if(umap[n] == 0){
				umap[n] = umap[n + umap[n+1]] = umap[n - umap[n-1]] = umap[n+1] + umap[n-1] + 1;
				maxlen = max(umap[n], maxlen);
			}
		}
		return maxlen;
	}
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.empty()) return 0;

		unordered_set<int> uset (nums.begin(), nums.end());

		int maxlen = 0, currlen;
		while(not uset.empty()){
			currlen = 0;
			int n = *uset.begin();
			
			int curr = n;;
			while(uset.find(curr) != uset.end()){
				uset.erase(curr);
				currlen++;
				curr++;
			}

			curr = n - 1;
			while(uset.find(curr) != uset.end()){
				uset.erase(curr);
				currlen++;
				curr--;
			}
			
			maxlen = max(currlen, maxlen);
		}

		return maxlen;
    }
};

// TLE
class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.empty()) return 0;
		unordered_set<int> uset;
		int Max = nums[0], Min = nums[0];
		for(auto n: nums){
			if(Max < n) Max = n;
			else if(Min > n) Min = n;
			uset.insert(n);
		}
		int maxlen = 0, currlen = 0;
		for(int n = Min; n <= Max; n++){
			if(uset.find(n) != uset.end()){
				maxlen = max(currlen, maxlen);
				currlen = 0;
			}
			else{
				currlen++;
			}
		}
		maxlen = max(maxlen, currlen);
		return maxlen;
    }
};

// TLE
class Solution4 {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.empty()) return 0;
		int maxlen = 0, currlen;

		for(auto n: nums){
			currlen = 1;
			int curr = n + 1;
			while(std::find(nums.begin(), nums.end(), curr) != nums.end())
				currlen++, curr++;

			curr = n - 1;
			while(std::find(nums.begin(), nums.end(), curr) != nums.end())
				currlen++, curr--;

			maxlen = max(maxlen, currlen);
		}
		
		return maxlen;
    }
};

int main(){
}


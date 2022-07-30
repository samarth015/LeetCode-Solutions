#include<bits/stdc++.h>
using namespace std;

class Solution {
	int n;
	unordered_map<int,int> memo;

	int lengthOfLIS(vector<int>& nums, int i){
		auto it = memo.find(i);
		if(it == memo.end()){
			int ans = 1;
			for(int j = i; j < n; j++){
				if(nums[j] > nums[i])
					ans = max(ans, 1+lengthOfLIS(nums, j));
			}
			it = memo.insert({i,ans}).first;
		}
		return it->second;
	}

	public:
		int lengthOfLIS(vector<int>& nums) {
			n = nums.size();
			memo[n] = memo[n+1] = 0;
			int res = 1;
			for(int i = 0; i < n; i++)
				res = max(res, lengthOfLIS(nums, i));
			return res;
		}
};

int main(){
}


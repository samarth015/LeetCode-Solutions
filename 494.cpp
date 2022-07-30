#include<bits/stdc++.h>
using namespace std;

// f(nums, t) = f(nums[1:], t+nums[0]) + f(nums[1:], t-nums[0])
// f(nums[n-1:n], t) if(+-nums[n-1] == t) return 1;

// Time limit exceeded but correct.
class Solution {
	int findTargetSumWays(vector<int>& nums, int target, int i) {
		if(i == nums.size() - 1) return (nums[i] == target) + (-nums[i] == target);
		return findTargetSumWays(nums, target + nums[i], i+1) + findTargetSumWays(nums, target - nums[i], i+1);
	}
	public:
	int findTargetSumWays(vector<int>& nums, int target) {
		return findTargetSumWays(nums, target, 0);
	}
};

//Also correct but time limit exceeded
class Solution2 {
	public:
		int findTargetSumWays(vector<int>& nums, int target) {
			vector<int> combinations {0};
			for(int i = 0; i < nums.size(); i++){
				vector<int> new_comb;
				for(auto c : combinations) new_comb.push_back(nums[i] + c), new_comb.push_back(c - nums[i]);
				combinations = move(new_comb);

			}
			return count(combinations.begin(), combinations.end(), target);
		}
};

class Solution3 {
	public:
		int findTargetSumWays(vector<int>& nums, int target) {
			unordered_map<int,int> combinations {{0,1}};
			for(int i = 0; i < nums.size(); i++){
				unordered_map<int,int> new_comb;
				for(auto c : combinations){
					new_comb[nums[i] + c.first] += c.second;
					new_comb[c.first - nums[i]] += c.second;
				}
				combinations = move(new_comb);
			}
			return combinations[target];
		}
};


int main(){
}


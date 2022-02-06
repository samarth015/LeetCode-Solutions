#include<bits/stdc++.h>
using namespace std;

// the order of the subsequence must be maintained so this is wrong
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
		vector<int> tmp (nums.begin(), nums.end());
		sort(tmp.begin(), tmp.end(), greater<int>());
		return {tmp.begin(), tmp.begin() + k};
    }
};

// This will work only for continuous subsequence so its wrong
class Solution2 {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
		int maxsum, max_left{0}, max_right{k-1}, currsum{ accumulate(nums.begin(), nums.begin() + k, 0) };
		maxsum = currsum;
		for(int i = k; i < nums.size(); i++){
			currsum = currsum + nums[i] - nums[i-k];
			if(maxsum < currsum) maxsum = currsum, max_left = i - k, max_right = i;
		}
		return {nums.begin() + max_left, nums.begin() + max_right + 1};
    }
};

int main(){
}


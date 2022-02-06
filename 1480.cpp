
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
		for(size_t i{1}; i < nums.size(); i++) nums[i] += nums[i-1];
		return nums;
	}

	//O(n) space
	/*
    vector<int> runningSum(vector<int>& nums) {
		vector<int> running_sum(nums.size());
		int sum = 0;
		for(size_t i{0}; i < nums.size(); i++){
			sum += nums[i];
			running_sum[i] = sum;
		}
		return running_sum;
    }
	*/
};

int main(){
}

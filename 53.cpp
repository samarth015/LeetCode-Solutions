
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int>& nums){
			int maxsum = nums.front(), curr_sum = 0;
			for(auto num : nums){
				curr_sum = std::max(curr_sum + num, num);
				maxsum = std::max(curr_sum, maxsum);
			}
			return maxsum;
		}
};

int main(){
}

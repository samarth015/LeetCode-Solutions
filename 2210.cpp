#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int countHillValley(vector<int>& nums) {
			int cnt = 0;
			int i = 1, j;
			while(nums[i] == nums[0]) i++;
			while(i < nums.size() - 1){
				j = i+1;
				while(j < nums.size() and nums[j] == nums[i])
					j++;
				if(j == nums.size()) break;
				auto pr = minmax({nums[i], nums[i-1], nums[j]});
				if(nums[i] == pr.first or nums[i] == pr.second)
					cnt++;
				i = j;
			}
			return cnt;
		}
};

class Solution2 {
	public:
		int countHillValley(vector<int>& nums) {
			auto it = unique(nums.begin(), nums.end());
			nums.erase(it, nums.end());
			int cnt = 0;
			for(int i = 1; i < nums.size()-1; i++){
				auto pr = minmax({nums[i], nums[i+1], nums[i-1]});
				if(nums[i] == pr.first or nums[i] == pr.second)
					cnt++;
			}
			return cnt;
		}
};

int main(){
}


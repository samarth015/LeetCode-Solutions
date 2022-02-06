#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> cnts (nums.size() + 1, 0), disnums{};
		for(auto n : nums) cnts[n]++;
		for(int i = 1; i < cnts.size(); i++) 
			if(cnts[i] == 0) disnums.push_back(i);
		return disnums;
    }
};

class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		unordered_set<int> nums_set {nums.begin(), nums.end()};
		vector<int> disnums {};
		for(int i = 0; i <= nums.size(); i++) 
			if(nums_set.find(i) == nums_set.end()) disnums.push_back(i);
		return disnums;
    }
};

int main(){
}


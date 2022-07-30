#include<bits/stdc++.h>
using namespace std;

// Most elegant
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> imap;
		int size = nums.size();
		for(int i = 0; i < size; i++){
			auto it { imap.find(target - nums[i]) };
			if(it != imap.end()) return {it->second, i};
			imap[nums[i]] = i;
		}
		return { -1, -1 };
    }
};


class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, vector<int>> umap;
		int size = nums.size();
		for(int i = 0; i < size; i++){
			umap[ nums[i] ].push_back(i);

			auto it = umap.find(target - nums[i]);
			if(it != umap.end()){
				auto& indexes = it->second;
				for(auto j : indexes) if(i != j) return {i, j};
			}
		}
		return { -1, -1 };
    }
};


class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_set<int> hashed_nums {nums.begin(), nums.end()};
		for(auto num: hashed_nums) {
			if(hashed_nums.find(target - num) != hashed_nums.end()){
				auto i1 { find(nums.begin(), nums.end(), num) },
					 i2 { find(nums.begin(), nums.end(), target - num) };

				if(i1 == i2){
					i2 = find( i2 + 1, nums.end(), num );
					if(i2 == nums.end()) continue;
				}

				return {(int)distance(nums.begin(), i1),
					    (int)distance(nums.begin(), i2)};
			}
		}
		return {-1,-1};
    }
};

int main(){
	Solution sol;
	vector<int> nums { 2,7,11,15 };
	vector<int> pair { sol.twoSum(nums , 9)};
	cout << pair[0] << ' ' << pair[1];
}

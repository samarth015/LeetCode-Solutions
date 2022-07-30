#include<bits/stdc++.h>
using namespace std;

// Removing elements one by one 
// Better space complexity
class Solution4 {
	list<int> curr;
	vector<vector<int>> permute(){
		if(curr.empty()) return {{}};
		vector<vector<int>> perms;

		int n = curr.size();
		for(int i = 1; i <= n; i++){
			int front = curr.front();
			curr.pop_front();
			auto remaining_perms = permute();
			for(auto &perm: remaining_perms){
				perm.push_back(front);
				perms.push_back(move(perm));
			}
			curr.push_back(front);
		}

		return perms;
	}

	public:
	vector<vector<int>> permute(vector<int>& nums) {
		curr = list<int>(nums.begin(), nums.end());
		return permute();
	}
};

// Selecting elements one by one building curr
// Better space complexity
class Solution3 {
	private:
		class permutation{
			vector<int> &nums;
			unordered_set<int> selected;
			size_t n;

			public:
			permutation(vector<int> &nums): nums{nums}, selected{}, n{nums.size()} {}

			vector<vector<int>> permute(){
				if(selected.size() == n) return {{}};

				vector<vector<int>> perms;
				for(int i = 0; i < n; i++){

					if(selected.find(i) == selected.end()){
						selected.insert(i);

						auto remaining_perms = permute();
						for(auto &perm: remaining_perms){
							perm.push_back(nums[i]);
							perms.push_back(move(perm));
						}

						selected.erase(i);
					}
				}
				return perms;
			}
		};

	public:
		vector<vector<int>> permute(vector<int>& nums) {
			return permutation{nums}.permute();
		}
};

// Removing elements one by one 
class Solution2 {
	vector<vector<int>> permute(unordered_set<int> curr){
		if(curr.empty()) return {{}};
		vector<vector<int>> perms;
		for(auto n: curr){
			auto remaining_nums = curr;
			remaining_nums.erase(n);
			auto remaining_perms = permute(move(remaining_nums));
			for(auto &perm: remaining_perms){
				perm.push_back(n);
				perms.push_back(move(perm));
			}
		}
		return perms;
	}

	public:
	vector<vector<int>> permute(vector<int>& nums) {
		return permute(unordered_set<int>(nums.begin(), nums.end()));
	}
};

// Selecting elements one by one building curr
class Solution {
	private:
		class permutation{
			vector<int> &nums;
			size_t n;

			public:
			permutation(vector<int> &nums): nums{nums}, n{nums.size()} {}

			vector<vector<int>> permute(unordered_set<int> curr){
				if(curr.size() == n) return {{}};
				vector<vector<int>> perms;
				for(int i = 0; i < n; i++){
					if(curr.find(i) == curr.end()){
						unordered_set<int> selected {curr.begin(), curr.end()};
						selected.insert(i);
						auto remaining_perms = permute(selected);
						for(auto &perm: remaining_perms){
							perm.push_back(nums[i]);
							perms.push_back(move(perm));
						}
					}
				}
				return perms;
			}
		};

	public:
		vector<vector<int>> permute(vector<int>& nums) {
			return permutation{nums}.permute({});
		}
};

int main(){
}


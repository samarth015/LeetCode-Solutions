#include<bits/stdc++.h>
using namespace std;

// Sol 4 is the preferred way of thinking for problems like these.
class Solution4 {
	vector<vector<int>> result;
	vector<int> comb;

	void combinationSum(vector<int>& candidates, int i, int target) {
		if(target == 0){
			result.push_back(comb);
			return;
		}
        if(target < 0 or i == candidates.size()) return;

			comb.push_back(candidates[i]);
			combinationSum(candidates, i, target - candidates[i]);
			comb.pop_back();
			combinationSum(candidates, i+1, target);
		}
	
	public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		result = vector<vector<int>>{};
		comb = vector<int>{};
		combinationSum(candidates, 0, target);
		return result;
	}
};

class Solution3 {
	vector<vector<int>> result;
	vector<int> comb;

	void combinationSum(vector<int>& candidates, int start, int target) {
		if(target < 0) return;
		if(target == 0){
			result.push_back(comb);
			return;
		}

		for(int i = start; i < candidates.size(); i++){
			comb.push_back(candidates[i]);
			combinationSum(candidates, i, target - candidates[i]);
			comb.pop_back();
		}
	}
	
	public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		result = vector<vector<int>>{};
		comb = vector<int>{};
		combinationSum(candidates, 0, target);
		return result;
	}
};

class Solution2 {
	class Combination{
		private:
			vector<int> &nums;
			int len;

		public:
			Combination(vector<int> &nums): nums{nums}, len{(int)nums.size()} {}

			vector<vector<int>> find(int start, int target){

				vector<vector<int>> combs;
				for(int i = start; i < len; i++){
					int n = nums[i];
					if(n == target){
						combs.push_back({n});
					}
					else if(n < target){
						auto remaining_combsum = find(i, target-n);

						for(auto &comb: remaining_combsum){
							comb.push_back(n);
							combs.push_back(move(comb));
						}
					}
				}
				return combs;
			}
	};

	public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		return Combination{candidates}.find(0, target);
	}
};

// Little more optimised. Dealing with all multiples in a while loop.
class Solution {
	vector<vector<int>> combinationSum(int start, vector<int>& nums, int target){

		vector<vector<int>> combs;
		for(int i = start; i < nums.size(); i++){
			int n = nums[i];
			int m = 1;
			while(m*n <= target){
				if(m*n == target){
					combs.push_back(vector<int>(m, n));
				}
				else{
					auto remaining_combsum = combinationSum(i+1, nums, target-m*n);

					for(auto &comb: remaining_combsum){
						for(int j = 1; j <= m; j++) comb.push_back(n);
						combs.push_back(move(comb));
					}
				}
				m++;
			}
		}
		return combs;
	}

	public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		return combinationSum(0, candidates, target);
	}
};

int main(){
	vector<int> v{21,46,35,20,44,31,29,23,45,37,33,34,39,42,24,40,41,26,22,38,36,27,25,49,48,43};
	auto res = Solution2{}.combinationSum(v, 71);
	for(auto r: res) {
		for(auto a: r) cout << a<< ' ';
		cout << endl;
	}
}


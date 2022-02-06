
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		/*
		vector<int> sortedSquares(vector<int>& nums){
			auto it1 {std::upper_bound(nums.begin(), nums.end(), -1)};
			auto it2 {it1 - 1};
			vector<int> result {}; 

			while(it1 != nums.end() and it2 != (nums.begin() - 1)){
				int sq1 = (*it1)*(*it1), sq2 = (*it2)*(*it2);
				if(sq1 >= sq2){
					result.push_back(sq2);
					it2--;
				}
				else{
					result.push_back(sq1);
					it1++;
				}
			}

			while(it2 != (nums.begin() - 1)){
				int sq2 = (*it2)*(*it2);
				result.push_back(sq2);
				it2--;
			}

			while(it1 != nums.end()){
				int sq1 = (*it1)*(*it1);
				result.push_back(sq1);
				it1++;
			}
			return result;
		}
		*/

		vector<int> sortedSquares(vector<int>& nums){
			int l = 0, r = nums.size() - 1;
			vector<int> result (nums.size());
			int ind = result.size() - 1;
			while(l <= r){
				if(abs(nums[l]) > abs(nums[r]))
					result[ind--] = pow(nums[l++], 2);
				else
					result[ind--] = pow(nums[r--], 2);
			}
			return result;
		}
};

int main(){
}


#include<bits/stdc++.h>
using namespace std;

#include <unordered_set>
class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums){
			sort(nums.begin(), nums.end());
			vector<vector<int>> result;
			int n = nums.size();
			nums.push_back(nums.back());
			for(int i = 0; i < n; i++){
				unordered_map<int,int> kmap;
				for(int j = i+1; j < n; j++){
					auto it = kmap.find( -nums[i] - nums[j] );
					if(it != kmap.end()){
						int k = it->second;
						result.push_back({nums[i], nums[j], nums[k]}); 
					}
					kmap[nums[j]] = j;
				}
				while(nums[i] == nums[i+1]) i++;
			}
			return result;
		}
};

int main(){
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<vector<int>> result;
		unordered_multiset<int> numset;

		void nSum(int n, int target, unordered_multiset<int>::iterator pos, unordered_multiset<int> exclude){
			if(n == 1){
				if(numset.count(target) > exclude.count(target)){
					vector<int> match {exclude.begin(), exclude.end()};
					match.push_back(target);
					result.push_back( match );
				}
			}
			else{
				for(auto it = pos; it != numset.end(); it++){
					exclude.insert( *it ); 
					auto new_pos = it; new_pos++;
					nSum(n - 1, target - *it, new_pos, exclude);
				}
			}
		}

	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target){
			result.clear(); numset.clear();
			numset.insert(nums.begin(), nums.end());
			nSum(4, target, numset.begin(), {});
			return result;
		}
};

int main(){
}


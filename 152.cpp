

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:

		int maxProduct(vector<int>& nums){
			int maxsf{1}, minsf{1}, max_product{1};
			for(auto n : nums){
				max_product = std::max( {max_product, maxsf * n, minsf * n} );
				int temp = maxsf;
				maxsf = std::max( {1, maxsf * n, minsf * n} );
				minsf = std::min( {1, temp * n, minsf * n} );
		}

		
		//brute force
		/*
		   int maxProduct(vector<int>& nums){
		   if(nums.size() == 1) return nums.front();

		   vector<int> products {};
		   int total_product, curr_product{1};

		   for(auto num : nums){
		   curr_product *= nums;
		   if(num < 0){
		   products.push_back(
		   }


		   }
		   */
};

int main(){
}

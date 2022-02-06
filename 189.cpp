#include<bits/stdc++.h>
using namespace std;

class Solution {
	// very slow solution
	/*
	private:
		 void rotateByOne(vector<int>& nums){
			 int temp = nums.back();
			 int i = nums.size() - 1;
			 while(i > 0){
				 nums[i] = nums[i-1];
				 i--;
			 }
			 nums[0] = temp;
		 }
		 
	public:
	void rotate(vector<int>& nums, int k){
		int equivalent_rotations = k % nums.size();
		for(int i = 0; i < equivalent_rotations; i++) rotateByOne(nums);
    }
	*/

	// copy whole array
	/*
	public:
	void rotate(vector<int>& nums, int k){
		k = k % nums.size();
		vector<int> rotated(nums.size());
		for(auto n : nums) rotated[k++ % nums.size()] = n;
		nums = std::move(rotated);
	}
	*/	
	void rotate(vector<int>& nums, int k){
		k = k % nums.size();
		vector<int> temp(nums.begin(), nums.begin() + (nums.size() - k));
		for(int i = nums.size() - k, j = 0; i < nums.size(); i++, j++) nums[j] = nums[i];
		for(int i = k, j = 0; i < nums.size(); i++, j++) nums[i] = temp[j];
	}
};


	int main(){
	}

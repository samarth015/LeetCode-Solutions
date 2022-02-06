#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int search(vector<int>& nums, int target, int left, int right){
			if(right < left) return -1;
			int mid = left + (right - left)/2;

			if(target < nums[mid]) return search(nums, target, left, mid - 1);
			else if(target > nums[mid]) return search(nums, target, mid + 1, right); 
			else return mid;
		}

	public:
		int search(vector<int>& nums, int target){
			if(target < nums.front() or target > nums.back()) return -1;
			return search(nums, target, 0, nums.size() - 1);
		}


	//Non recursive solution
	/*
		int search(vector<int>& nums, int target){
			if(target < nums.front() or target > nums.back()) return -1;
			int left = 0, right = nums.size() - 1, mid;
			while(left <= right){
				mid = left + (right - left)/2;
				if(target < nums[mid]) right = mid - 1;
				else if(nums[mid] < target) left = mid + 1;
				else return mid;
			}
			return -1;
		}
		*/
};

int main(){

}

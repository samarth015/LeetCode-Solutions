
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int searchInsert(vector<int>& nums, int target){
			if(target < nums.front()) return 0;
			if(target > nums.back()) return nums.size();

			int lo = 0, hi = nums.size() - 1, mid;
			while(lo < hi){
				mid = lo + (hi - lo)/2;
				if(nums[mid] > target) hi = mid;
				else if(nums[mid] < target) lo = mid + 1;
				else return mid;
			}
			return hi;
		}
};

int main(){
}

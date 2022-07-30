#include<bits/stdc++.h>
using namespace std;

// This is overengineered and no better than Sol2 even in terms of efficiency.
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
		if(nums.size() == 1) return true;
		auto it = find_if(nums.begin(), nums.end(), [val=nums[0]](auto n){return val != n;});
		if(it == nums.end()) return true;

		function<bool(int,int)> predicate; 
		if(*nums.begin() < *it) predicate = less<int>{}; 
		else predicate = greater<int>{};

		return is_sorted(it, nums.end(), predicate);
    }
};

// It might look like a 2 wipe (2N) but its always 1 wipe (N) if u think carefully enough.
class Solution2 {
public:
    bool isMonotonic(vector<int>& nums) {
		return is_sorted(nums.begin(), nums.end(), less<int>{}) or is_sorted(nums.begin(), nums.end(), greater<int>{});
};

int main(){
}


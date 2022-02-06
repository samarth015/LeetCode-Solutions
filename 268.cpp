#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		int left = 0, right = nums.size(), mid;
		while(left < right){
			mid = (left + right)/2;
			if(nums[mid] > mid) right = mid;
			else left = mid + 1;
		}
		return left;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
		int missing, n = nums.size();
		missing = n;
		for(int i{0}; i < n; i++) missing ^= i ^ nums[i];
		return missing;
    }
};

class Solution3 {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int totalsum = ((n+1) * n)/2;
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		return totalsum - sum;
    }
};

int main(){
}


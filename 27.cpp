#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		return std::remove(nums.begin(), nums.end(), val) - nums.begin();
    }
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
		int k = 0;
		for(size_t i = 0; i < nums.size(); i++)
			if(nums[i] != val) nums[k++] = nums[i];
		return k;
    }
};

int main(){
}


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int k = 0;
		for(int i = 0; i < nums.size(); i++)
			if(nums[i] != nums[k]) nums[++k] = nums[i];
		return k + 1;
    }
};

int main(){
}

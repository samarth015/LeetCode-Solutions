#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums){
		int expected_val = nums[0], nopers {0};
		for(int i = 1; i < nums.size(); i++){
			expected_val = max(expected_val + 1, nums[i]); 
			nopers += expected_val - nums[i];
		}
		return nopers;
    }
};

int main(){
}


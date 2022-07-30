#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		for(int i = 0; i < nums.size() - 1; i++){
			int j = i;
			while(j >= 0 and nums[j] + j <= i) j--;
			if(j < 0) return false;
		}
		return true;
    }
};

int main(){
}


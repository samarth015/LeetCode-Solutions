#include<bits/stdc++.h>
using namespace std;

// The final combination of houses to maximize sum will include either of first and last or neither of them.
// But it wont include both of them.

// bottom-up optimization
// p1 stores the max including n [0..n] and p2 stores the max excluding n [0..n-1]
// Note : p1 and p2 might store the same value.
class Solution {
	int rob(vector<int>& nums, int start, int end){
		int p1 = 0, p2 = 0;
		for(int i = start; i < end; i++){
			int tmp = p1;
			p1 = max(p1, p2 + nums[i]);
			p2 = tmp;
		}
		return p1;
	}
public:
    int rob(vector<int>& nums) {
		int n = nums.size();
		if(n == 1) return nums.back();
		return max(rob(nums, 1, n), rob(nums, 0, n-1));
	}
};

// top-down memo
class Solution3 {
	vector<int> *nums;
	int size;
	vector<int> memo;

	int rob(int i){
		if(memo[i] == -1)
			memo[i] = max((*nums)[i]+rob(i+2), rob(i+1));
		return memo[i];
	}

public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums.front();

        this->nums = &nums;
		size = nums.size();

		memo = vector<int>(size+2, -1);
		memo[size+1] = memo[size] = 0;
		int a = max(rob(1), rob(2));
        
        size -= 1;
		std::fill(memo.begin(), memo.end(), -1);
		memo[size+1] = memo[size] = 0;
		int b = max(rob(0), rob(1));
        
		return max(a,b);
	}
};

int main(){
}


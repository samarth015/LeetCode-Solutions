#include<bits/stdc++.h>
using namespace std;

// bottom-up optimization
// p1 stores the max including n [0..n] and p2 stores the max excluding n [0..n-1]
// Note : p1 and p2 might store the same value.
class Solution2 {
public:
    int rob(vector<int>& nums) {
		int p1 = 0, p2 = 0;
		for(auto n : nums){
			int tmp = p1;
			p1 = max(p1, p2 + n);
			p2 = tmp;
		}
		return p1;
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
		size = nums.size();
		memo = vector<int>(size+2, -1);
		memo[size] = memo[size+1] = 0;
		this->nums = &nums;
		return max(rob(0), rob(1));
	}
};


// Keeps a track of whether the largest in previous subsequence (1 to n-1) includes the rightmost element.
class Solution {
public:
    int rob(vector<int>& nums) {
		bool includes_rightmost = false;
		int largest = 0, sec_lar = 0;
		for(auto n : nums){
			if(includes_rightmost){
				if(sec_lar + n > largest){
					swap(largest, sec_lar);
					largest += n;
					includes_rightmost = true;
				}
				else{
					sec_lar += n;
					includes_rightmost = false;
				}
			}
			else{
				sec_lar = largest;
				largest += n;
				includes_rightmost = true;
			}
		}
		return largest;
    }
};



int main(){
}


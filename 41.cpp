#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int fast{0}, slow{0};
		while(fast < nums.size()){
			if(nums[fast] <= 0){
				std::swap(nums[fast], nums[slow]);
				slow++;
			}
			fast++;
		}
		int n = fast - slow;
		std::unordered_set<int> pos_nums{ nums.begin() + slow, nums.end() };
		for(int i = 1; i <= n; i++) if(pos_nums.find(i) == pos_nums.end()) return i;
		return n + 1;
    }
};

int main(){
}


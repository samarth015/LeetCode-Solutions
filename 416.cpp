#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		unordered_set<int> ust {0};
		for(auto n: nums){
			unordered_set<int> next;
			for(auto e: ust){
				next.insert(abs(e-n));
				next.insert(abs(e+n));
			}
			ust = move(next);
		}

		return ust.find(0) != ust.end();
    }
};

int main(){
}


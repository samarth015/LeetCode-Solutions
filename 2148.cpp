#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int countElements(vector<int>& nums) {
			auto minmaxpair = std::minmax_element(nums.begin(), nums.end());
			int mi {*minmaxpair.first}, ma = {*minmaxpair.second}; 
			int cnt {0};
			for(auto n : nums) if( mi < n && n < ma ) cnt++;
			return cnt;
		}
};

int main(){
}


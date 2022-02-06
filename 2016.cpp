#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maximumDifference(vector<int>& nums){
			int min_so_far = nums.front(), maxdiff = 0;
			for(auto n : nums){
				if(min_so_far > n) min_so_far = n;
				else if(maxdiff < n - min_so_far) maxdiff = n - min_so_far;
			}
			return maxdiff;
		}
};

int main(){
}

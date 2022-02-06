
#include<bits/stdc++.h>
using namespace std;

#include <algorithm>
class Solution {
	public:
		int majorityElement(vector<int>& nums){
			std::sort(nums.begin(), nums.end());
			int max_ele = nums.front(), curr_ele{nums.front()}, curr_frequency{0}, max_frequency{1};
			for(auto n : nums){
				if(n == curr_ele){
					curr_frequency++;
				}
				else{
					if(max_frequency < curr_frequency){
						max_frequency = curr_frequency;
						max_ele = curr_ele;
					}
					curr_frequency = 1;
					curr_ele = n;
				}
			}
			if(max_frequency < curr_frequency){
				max_frequency = curr_frequency;
				max_ele = curr_ele;
			}
			return max_ele;
		}
};

int main(){
}

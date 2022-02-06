

#include<bits/stdc++.h>
using namespace std;

#include <algorithm>
class Solution {
	public:
		vector<int> majorityElement(vector<int>& nums) {
			std::sort(nums.begin(), nums.end());
			int curr_ele{nums.front()}, curr_frequency{0};
			vector<int> majeles;

			for(auto n : nums){
				if(n == curr_ele){
					curr_frequency++;
				}
				else{
					if(curr_frequency > nums.size()/3)
						majeles.push_back(curr_ele);
					curr_frequency = 1;
					curr_ele = n;
				}
			}
			if(curr_frequency > nums.size()/3)
				majeles.push_back(curr_ele);

			return majeles;
		}
};

int main(){
}

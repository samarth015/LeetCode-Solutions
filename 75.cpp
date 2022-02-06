#include<bits/stdc++.h>
using namespace std;

//two pointer
class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int l = 0, r = nums.size() - 1, i = 0;
			while(i <= r){
				if(nums[i] == 0){
					nums[i] = nums[l];
					nums[l] = 0;
					i++, l++;
				}
				else if(nums[i] == 2){
					nums[i] = nums[r];
					nums[r] = 2;
					r--;
				}
				else{
					i++;
				}
			}
		}
};

//straight forward
class Solution2 {
	public:
		void sortColors(vector<int>& nums) {
			size_t ones{}, twos{}, zeros{};
			ones = std::count(nums.begin(), nums.end(), 1);
			twos = std::count(nums.begin(), nums.end(), 2);
			zeros = nums.size() - ones - twos;
			size_t i{};
			while(zeros--) nums[i++] = 0;
			while(ones-- ) nums[i++] = 1;
			while(twos-- ) nums[i++] = 2;
		}
};

int main(){
}


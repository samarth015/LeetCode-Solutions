#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		//Less optimal
		/*
		void moveZeroes(vector<int>& nums){
			int j = 0;
			for(int i = 0; i < nums.size(); i++){
				if(nums[i] != 0){ 
					if(i!=j) nums[j] = nums[i];
					j++;
				}
			}
			while(j < nums.size()){
				nums[j] = 0;
				j++;
			}
		}
		*/

		//More Optimal
		/*	
		void moveZeroes(vector<int>& nums){
			int j = 0;
			for(int i = 0; i < nums.size(); i++){
				if(nums[i] != 0){ 
					if(i!=j) std::swap(nums[i],nums[j]);
					j++;
				}
			}
		}
		*/

		//SnowBall solution
		void moveZeroes(vector<int>& nums){
			int snowBallSize = 0;
			for(int i = 0; i < nums.size(); i++){
				if(nums[i] == 0)
					snowBallSize++;
				else if(snowBallSize > 0){
					nums[i - snowBallSize] = nums[i];
					nums[i] = 0;
				}
		}
};

int main(){
}

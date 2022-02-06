
#include<bits/stdc++.h>
using namespace std;

// For any given tower, the maximum area will be formed with a tower, in the set of 
// towers with height greater than or equal to it, that is most distantly located from it( with max(j-i) val ) 

class Solution {
	public:
		int maxArea(vector<int>& height){
			int maxarea {0}, currarea;
			size_t i{0}, j{height.size()};
			while(i < j){
				currarea = (j - i) * std::min(height[i], height[j]);
				if(maxarea < currarea) maxarea = currarea;
				int curr_smaller_tower = std::min(height[i], height[j]);
				while(height[i] < curr_smaller_tower) i++;
				while(height[j] < curr_smaller_tower) j--;
			}
			return maxarea; 
		}

		//brute force
		/*
		   public:
		   int maxArea(vector<int>& height){
		   int maxarea {0};
		   for(int i = 0; i < height.size() - 1; i++){
		   for(int j = i + 1; j < height.size(); j++){
		   maxarea = std::max(maxarea, (j - i)*std::min(height[i], height[j]));
		   }
		   }
		   return maxarea;
		   }
		   */
};

int main(){
}

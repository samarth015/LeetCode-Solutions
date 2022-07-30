
#include<bits/stdc++.h>
using namespace std;

// For any given tower, the maximum area will be formed with a tower belongs to the set of 
// towers with height greater than or equal to it, that is most distantly located from it( with max(j-i) val ) 

// Cleaner
class Solution {
	public:
		int maxArea(vector<int>& height){
			int maxarea {0}, currarea;
			size_t i{0}, j{height.size() - 1};
			while(i < j){
				int smaller = std::min(height[i], height[j]);
				currarea = (j - i) * smaller;
				if(maxarea < currarea) maxarea = currarea;
				if(height[i] == smaller) i++;
				else j--;
			}
			return maxarea;
		}
};

// Faster
class Solution2 {
	public:
		int maxArea(vector<int>& height){
			int maxarea {0}, currarea;
			size_t i{0}, j{height.size() - 1};
			while(i < j){
				int smaller = std::min(height[i], height[j]);
				currarea = (j - i) * smaller;
				if(maxarea < currarea) maxarea = currarea;
				while(i < j and height[i] <= smaller) i++;
				while(i < j and height[j] <= smaller) j--;
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

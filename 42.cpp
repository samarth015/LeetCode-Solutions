#include<bits/stdc++.h>
using namespace std;

// If u notice carefully, the amount of water that is stored above any bar is min(maxleft, maxright) - height[i] 
// Find the tallest bar, then solve for left and right side of the tallest. maxright for the left region is always
// the tallest bar and maxleft for the right region is always the tallest bar.
// You can use the same principles to solve it with a two pointer approach.

// Most elegant
class Solution2 {
public:
    int trap(vector<int>& height) {
		if(height.empty()) return 0;

		int maxpeak = distance(height.begin(), max_element(height.begin(), height.end()));

		int i = 1, maxleft = height[0], trapped_water = 0;
		while(i < maxpeak){
			if(maxleft > height[i])
				trapped_water += maxleft - height[i];
			else maxleft = height[i];
			i++;
		}

		int n = height.size(), maxright = height[n - 1];
		i = n - 2; 
		while(i > maxpeak){
			if(maxright > height[i])
				trapped_water += maxright - height[i];
			else maxright = height[i];
			i--;
		}

		return trapped_water;
    }
};

// Two pointer 
class Solution3{
public:
    int trap(vector<int>& height){
		if(height.empty()) return 0;
		int  l = 0, r = height.size() - 1;
		int maxleft = height[l], maxright = height[r], trapped_water = 0;
		while(l < r){
			if(maxleft < maxright){
				l++;
				maxleft = max(maxleft, height[l]);
				trapped_water += maxleft - height[l]; 
			}
			else{
				r--;
				maxright = max(maxright, height[r]);
				trapped_water += maxright - height[r]; 
			}
		}
		return trapped_water;
	}
};

class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();

		int i = n - 1;
		while(i > 0 and height[i-1] >= height[i]) i--;
		int rightmostpeak = i;

		i = 0;
		while(i < n - 1 and height[i] <= height[i+1]) i++;
		int leftmostpeak = i, highestpeak = i;

		int trapped_water = 0;
		while(i < rightmostpeak){
			while(i < rightmostpeak and height[i] >= height[i+1]) i++;
			while(i < rightmostpeak and height[i] <= height[i+1]) i++;

			int localwaterheight = min(height[highestpeak], height[i]);
			for(int j = highestpeak; j < i; j++){
				if(height[j] < localwaterheight){
					trapped_water += height[j] - localwaterheight;
					height[j] = localwaterheight;
				}
			}

			if(height[highestpeak] <= height[i]) highestpeak = i;
		}
		return trapped_water;
    }
};

int main(){
	vector<int> v = vector<int>{0,1,0,2,1,0,1,3,2,1,2,1};
	cout << Solution3{}.trap(v);
}


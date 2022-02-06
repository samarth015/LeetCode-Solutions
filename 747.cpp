#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> nums) {
        if(nums.size() == 1) return 0;
		int Max, secMax;
		if(nums[0] > nums[1]) Max = 0, secMax = 1;
		else Max = 1, secMax = 0;
		for(int i = 2; i < nums.size(); i++){
			if(nums[i] > nums[secMax]){
				if(nums[i] > nums[Max]){
					secMax = Max;
					Max = i;
				}
				else{
					secMax = i;
				}
			}
		}
		cout << Max << ' ' << secMax << endl;
		return ( nums[Max] >= 2 * nums[secMax] ? Max : -1 );
    }
};

int main(){
	cout << Solution{}.dominantIndex( vector<int>{1,2,3,4} );
}


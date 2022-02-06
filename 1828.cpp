// Try doing this using KD tree that solves this problem in log time apparantly

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
			vector<int> ans {};
			for(auto query : queries){
				int count{0};
				for(auto point : points){
					int sum = pow(point[0] - query[0], 2) + pow(point[1] - query[1], 2) - pow(query[2], 2) ; 
					if(sum <= 0) count++;
				}
				ans.push_back(count);
			}
			return ans;
		}
};

int main(){
}


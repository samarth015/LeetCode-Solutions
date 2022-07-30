#include<bits/stdc++.h>
using namespace std;

class Solution {
	array<int, 5> offset;
	bool pacific, atlantic;
	vector<vector<int>> *heights;
	int n, m;

	bool indexIsValid(int i, int j){
		return 0 <= i and i < m and 0 <= j and j < n;
	}

	void flowWater(int i, int j){
		if(i == 0 or j == 0) pacific = true;
		if(i == m-1 or j == n-1) atlantic = true;
		if(pacific and atlantic) return;

		int height = (*heights)[i][j];
		(*heights)[i][j] += 1;

		for(int k = 0; k < 4; k++){
			int inew = i + offset[k], jnew = j + offset[k+1];
			if(indexIsValid(inew, jnew) and (*heights)[inew][jnew] <= height)
				flowWater(inew, jnew);
		}

		(*heights)[i][j] -= 1;
	}

public:
	Solution(): offset{0,1,0,-1,0} {}

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		this->heights = &heights;
		m = heights.size(), n = heights.front().size();
		vector<vector<int>> res;

		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				pacific = atlantic = false;
				flowWater(i, j);
				if(pacific and atlantic) res.push_back({i,j});
			}
		}

		return res;
    }
};

int main(){
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
			vector<int> row_tallest, col_tallest;
			for(auto& row : grid) row_tallest.push_back( *max_element(row.begin(), row.end()) );
			for(int i = 0; i < grid.back().size(); i++) col_tallest.push_back( (*max_element(grid.begin(), grid.end(), 
							[i](auto &a, auto &b){ return a[i] < b[i]; } ))[i] );
			int sum = 0;
			for(int i = 0; i < grid.size(); i++){ 
				for(int j = 0; j < grid.back().size(); j++){ 
					sum += min(row_tallest[i], col_tallest[j]) - grid[i][j];
				}
			}
			return sum;
		}
};

int main(){
}


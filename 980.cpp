#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
		int i_start, j_start, i_end, j_end;
		for(int i = 0; i < grid.size(); i++){
			for(int j = 0; j < grid.front().size(); j++){
				if(grid[i][j] == 1) i_start = i, j_start = j;
				else if(grid[i][j] == 2) i_end = i, j_end = j;
			}
		}

		int paths = 0;
		stack<pair<int, int>> st {};

		st.push(make_pair(i_start, j_start));
		while(not st.empty()){
			if(
    }
};

int main(){
}


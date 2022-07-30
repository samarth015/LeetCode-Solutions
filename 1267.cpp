#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid){
		int m = grid.size(), n = grid.back().size();
		vector<int> rows(m), cols(n);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++) 
				if(grid[i][j]) rows[i]++, cols[j]++;
		}
		int res = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++) 
				res += grid[i][j] and (rows[i] > 1 or cols[j] > 1);
		}
		return res; 
    }
};

class Solution2 {
public:
    int countServers(vector<vector<int>>& grid){
		int m = grid.size(), n = grid.back().size();
		vector<bool> rows(m), cols(n);
		for(int i = 0; i < m; i++){
			int s = 0;
			for(int j = 0; j < n; j++) s += grid[i][j]; 
			rows[i] = s > 1;
		}
		for(int i = 0; i < n; i++){
			int s = 0;
			for(int j = 0; j < m; j++) s += grid[j][i]; 
			cols[i] = s > 1;
		}
		int res = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++) res += grid[i][j] and (rows[i] or cols[j]);
		}
		return res; 
    }
};

int main(){
	vector<vector<int>> grid {{1,1,0,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,1}};
	 cout << Solution{}.countServers(grid);
}


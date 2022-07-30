#include<bits/stdc++.h>
using namespace std;

// DFS
class Solution {
private:
	class IslandOper{
		private:
			int m, n;
			vector<vector<char>> &grid;

			bool indexIsValid(int i, int j){
				return 0 <= i and i < m and 0 <= j and j < n;
			}

		public:
			IslandOper(vector<vector<char>> &grid):
				m{(int)grid.size()},
				n{(int)grid.back().size()},
				grid{grid}
			{}

		void forgetIsland(int i, int j){
			if(indexIsValid(i,j) and grid[i][j] == '1'){
				grid[i][j] = '0';
				forgetIsland(i+1, j);
				forgetIsland(i-1, j);
				forgetIsland(i, j-1);
				forgetIsland(i, j+1);
			}
		}
	};
    
public:
    int numIslands(vector<vector<char>>& grid){
		auto ioper = IslandOper{grid};
		int m = grid.size(), n = grid.back().size();
		int cnt = 0;
        for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(grid[i][j] == '1'){
					cnt++;
					ioper.forgetIsland(i, j);
				}
			}
        }
		return cnt;
    }
};


// BFS
class Solution2 {
private:
	class IslandOper{
		private:
			int m, n;
			vector<vector<char>> &grid;

			bool indexIsValid(int i, int j){
				return 0 <= i and i < m and 0 <= j and j < n;
			}

		public:
			IslandOper(vector<vector<char>> &grid):
				m{(int)grid.size()},
				n{(int)grid.back().size()},
				grid{grid}
			{}

		void forgetIsland(int i, int j){
			queue<pair<int,int>> q;
			q.push({i,j});
			while(not q.empty()){
				int n = q.size();
				while(n--){
					auto ij = q.front();
					q.pop();
					i = ij.first, j = ij.second;
					if(indexIsValid(i,j)){
						grid[i][j] = '0';
						q.push({i+1,j});
						q.push({i-1,j});
						q.push({i,j+1});
						q.push({i,j-1});
					}
				}
			}
		}
	};
    
public:
    int numIslands(vector<vector<char>>& grid){
		auto ioper = IslandOper{grid};
		int m = grid.size(), n = grid.back().size();
		int cnt = 0;
        for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(grid[i][j] == '1'){
					cnt++;
					ioper.forgetIsland(i, j);
				}
			}
        }
		return cnt;
    }
};


int main(){
}


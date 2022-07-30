#include<bits/stdc++.h>
using namespace std;

// bfs
class Solution {
	int m, n;
	vector<vector<int>> *grid;

	bool indexIsValid(int i, int j){
		return 0 <= i and i < m and 0 <= j and j < n;
	}

	int findArea(int i, int j){
		int area = 0;
		queue<pair<int,int>> q;
		q.push({i,j});
		while(!q.empty()){
			int n = q.size();
			while(n--){
				auto pr = q.front();
				q.pop();
				i = pr.first, j = pr.second;
				if(indexIsValid(i, j) and (*grid)[i][j] == 1){
					area++;
					(*grid)[i][j] = 0;
					q.push({i-1,j});
					q.push({i+1,j});
					q.push({i,j+1});
					q.push({i,j-1});
				}
			}
		}
		return area;
	}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		m = grid.size(), n = grid.front().size();
        this->grid = &grid;

		int area, max_area = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(grid[i][j] == 1){
					area = findArea(i, j);
					max_area = max(max_area, area);
				}
			}
		}
		return max_area;
    }
};

// dfs
class Solution2 {
	int m, n;
	vector<vector<int>> *grid;

	bool indexIsValid(int i, int j){
		return 0 <= i and i < m and 0 <= j and j < n;
	}

	int findArea(int i, int j){
		if(indexIsValid(i, j) and (*grid)[i][j] == 1){
			(*grid)[i][j] = 0;
			return 1 +
				+ findArea(i+1,j)
				+ findArea(i-1,j)
				+ findArea(i,j+1)
				+ findArea(i,j-1);
		}
		else 
			return 0;
	}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		m = grid.size(), n = grid.front().size();
        this->grid = &grid;

		int area, max_area = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(grid[i][j] == 1){
					area = findArea(i, j);
					max_area = max(max_area, area);
				}
			}
		}
		return max_area;
    }
};

int main(){
}


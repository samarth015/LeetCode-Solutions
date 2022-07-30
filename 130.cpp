#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<char>> *board;
	int m, n;

	bool indexIsValid(int i, int j){
		return 0 <= i and i < m and 0 <= j and j < n;
	}

	void markRegionUnsurrounded(int i, int j){
		if(indexIsValid(i,j) and (*board)[i][j] == 'O'){
			(*board)[i][j] = '#';
			markRegionUnsurrounded(i+1,j);
			markRegionUnsurrounded(i-1,j);
			markRegionUnsurrounded(i,j+1);
			markRegionUnsurrounded(i,j-1);
		}
	}

public:
    void solve(vector<vector<char>>& board){
		m = board.size(), n = board.front().size();
		this->board = &board;

		for(int i = 0; i < m; i++){
			markRegionUnsurrounded(i, 0);
			markRegionUnsurrounded(i, n-1);
		}
		for(int j = 0; j < n; j++){
			markRegionUnsurrounded(0, j);
			markRegionUnsurrounded(m-1, j);
		}

		for(auto &row: board){
			for(char &c: row){
				if(c == 'O') c = 'X';
				else if(c == '#') c = 'O';
			}
		}

    }
};

int main(){
}


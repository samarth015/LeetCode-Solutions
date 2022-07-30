#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<string>> result;
	vector<string> config;
	int N;

	bool QueenPlacementIsValid(int i, int j){
		// top
		for(int k = i; k >= 0; k--) 
			if(config[k][j] == 'Q') return false;

		// top left
		int m = i, n = j;
		while(m >= 0 and n >= 0){
			if(config[m][n] == 'Q') return false;
			m--, n--;
		}

		//top right
		m = i, n = j;
		while(m >= 0 and n < N){
			if(config[m][n] == 'Q') return false;
			m--, n++;
		}
		return true;
	}

	void solveNQueens(int i, int j, int queens_placed){
		if(queens_placed == N){
			result.push_back(config);
			return;
		}
		if(j == N) i++, j = 0;
		if(i == N) return;

		// Dont place any queen at i,j
		solveNQueens(i, j+1, queens_placed);

		// If a queen can be placed at i,j then place it
		if(QueenPlacementIsValid(i, j)){
			config[i][j] = 'Q';
			solveNQueens(i+1, 0, 1+queens_placed);
			config[i][j] = '.';
		}
	}

public:
    vector<vector<string>> solveNQueens(int n) {
		config = vector<string>(n, string(n, '.'));
		result = vector<vector<string>>{};
		N = n;
		solveNQueens(0, 0, 0);
		return result;
    }
};

int main(){
}


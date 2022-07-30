#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<char>> *board;

	array<array<bool,10>, 9> row_nums, col_nums, box_nums;

	bool isSolved(int i, int j){
		if(j == 9) 
			j = 0, i++;
		if(i == 9)
			return true;

		if((*board)[i][j] != '.')
			return isSolved(i, j+1);

		for(int n = 1; n <= 9; n++){
			int k = (i/3)*3+j/3;
			if(not(row_nums[i][n] or col_nums[j][n] or box_nums[k][n])){
				row_nums[i][n] = col_nums[j][n] = box_nums[k][n] = true;
				if(isSolved(i, j+1)){
					(*board)[i][j] = n + '0';
					return true;
				}
				row_nums[i][n] = col_nums[j][n] = box_nums[k][n] = false;
			}
		}
		return false;
	}

public:
	Solution(): row_nums{}, col_nums{}, box_nums{} {}
	
    void solveSudoku(vector<vector<char>>& board) {
        this->board = &board;

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					int k = (i/3)*3+j/3;
					int n = board[i][j] - '0';
					row_nums[i][n] = col_nums[j][n] = box_nums[k][n] = true;
				}
			}
		}
		isSolved(0,0);
    }
};

int main(){
}


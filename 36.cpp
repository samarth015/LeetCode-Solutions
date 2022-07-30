#include<bits/stdc++.h>
using namespace std;

// Readible Solution
class Solution {
	private:
		bool rowsValid(vector<vector<char>>& board){
			for(auto &row: board){
				vector<int> encountered (10, false);
				for(char n: row){
					if(n != '.'){
						n -= '0';
						if(encountered[n]) return false;
						encountered[n] = true;
					}
				}
			}
			return true;
		}

		bool columnsValid(vector<vector<char>>& board){
			for(int i = 0; i < 9; i++){
				vector<int> encountered (10, false);
				for(int j = 0; j < 9; j++){
					char n = board[j][i];
					if(n != '.'){
						n -= '0';
						if(encountered[n]) return false;
						encountered[n] = true;
					}
				}
			}
			return true;
		}

		bool subBoxesvalid(vector<vector<char>>& board){
			for(int i = 0; i < 9; i+=3){
				for(int j = 0; j < 9; j+=3){
				vector<int> encountered (10, false);
					for(int x = i; x < i + 3; x++){
						for(int y = j; y < j + 3; y++){
							int n = board[x][y];
							if(n != '.'){
								n -= '0';
								if(encountered[n]) return false;
								encountered[n] = true;
							}
						}
					}
				}
			}
			return true;
		}
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			return rowsValid(board) and columnsValid(board) and subBoxesvalid(board);
		}
};

// Clever solution
class Solution2 {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			int usedInRow[9][10] = {0}, usedInCol[9][10] = {0}, usedInSubBox[9][10] = {0};
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					int n = board[i][j];
					if(n == '.') continue;
					n -= '0';
					int k = (i/3)*3 + (j/3);
					if(usedInRow[i][n] or usedInCol[j][n] or usedInSubBox[k][n]) return false;
					usedInRow[i][n] = usedInCol[j][n] = usedInSubBox[k][n] = 1;
				}
			}
			return true;
		}
};
	

int main(){
}


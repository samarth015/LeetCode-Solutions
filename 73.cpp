#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void setZeroes(vector<vector<int>>& matrix) {

			auto rowlen{matrix.size()} , collen{matrix.front().size()};
			bool first_row_to_be_zeroed{false}, first_col_to_be_zeroed{false};

			if(matrix[0][0] == 0){
				first_row_to_be_zeroed = first_col_to_be_zeroed = true;
			}
			else{
				for(int i = 1; i < rowlen; i++){
					if(matrix[i][0] == 0){
						first_col_to_be_zeroed = true; break;
					}
				}
				for(int i = 1; i < collen; i++){
					if(matrix[0][i] == 0){
						first_row_to_be_zeroed = true; break;
					}
				}
			}
			for(int i = 1; i < rowlen; i++){
				for(int j = 1; j < collen; j++){
					if(matrix[i][j] == 0) matrix[i][0] = 0, matrix[0][j] = 0;
				}
			}

			for(int i = 1; i < rowlen; i++)
				if(matrix[i][0] == 0)
					for(int j = 0; j < collen; j++) matrix[i][j] = 0; 
			for(int i = 1; i < collen; i++)
				if(matrix[0][i] == 0)
					for(int j = 0; j < rowlen; j++) matrix[j][i] = 0; 

			if(first_col_to_be_zeroed)
				for(int i = 0; i < rowlen; i++) matrix[i][0] = 0;
			if(first_row_to_be_zeroed)
				for(int i = 0; i < collen; i++) matrix[0][i] = 0;
		}
};

class Solution2 {
	public:
		void setZeroes(vector<vector<int>>& matrix) {
			set<int> rows{}, cols{};
			auto rowlen{matrix.size()} , collen{matrix.front().size()};
			for(int i = 0; i < rowlen; i++){
				for(int j = 0; j < collen; j++){
					if(matrix[i][j] == 0) rows.insert(i), cols.insert(j); 
				}
			}
			for(auto row : rows)
				for(int i = 0; i < collen; i++) matrix[row][i] = 0; 
			for(auto col : cols)
				for(int i = 0; i < rowlen; i++) matrix[i][col] = 0; 
		}
};

int main(){
}


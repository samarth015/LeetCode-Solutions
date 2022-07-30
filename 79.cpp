#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool dfs(int i, int j, int chidx, vector<vector<char>> &board, string &word){
		if(chidx == word.size()) return true;
		if(not (0 <= i and i < board.size() and 0 <= j and j < board.back().size())) return false;

		char currch = board[i][j];
		if(word[chidx] != currch) return false;

		chidx++;
		board[i][j] = -1;
		bool found = dfs(i+1, j, chidx, board, word) or
					 dfs(i-1, j, chidx, board, word) or
					 dfs(i, j+1, chidx, board, word) or
					 dfs(i, j-1, chidx, board, word) ;

		board[i][j] = currch;
		return found;
	}

public:
    bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(), n = board.back().size();
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(dfs(i, j, 0, board, word))
					return true;
			}
		}
		return false;
    }
};

int main(){
}


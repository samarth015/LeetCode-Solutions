#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid.back().size();
		int size = m * n;
		k = k % size;
		vector<vector<int>> res(m, vector<int>(n));
		for(int i = 0,j = k; i < size; i++, j = (j + 1) % size)
			res[j/n][j%n] = grid[i/n][i%n];
		return res;
    }
};

int main(){
}


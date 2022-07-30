#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
            if(m*n != original.size()) return {};
			vector<vector<int>> result(m, vector<int>(n));
			int i = 0;
			for(int i = 0; i < m; i++)
				for(int j = 0; j < n; j++)
					result[i][j] = original[i*n + j];
			return result;
		}
};

class Solution2 {
	public:
		vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
			int size = original.size();
            if(m*n != size) return {};
			vector<vector<int>> result(m, vector<int>(n));
			for(int i = 0; i < size; i++)
				result[i/n][i%n] = original[i];
			return result;
		}
};

int main(){
}


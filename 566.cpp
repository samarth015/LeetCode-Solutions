#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		int m = mat.size(), n = mat.back().size();
		if(m * n != c * r) return mat;
		vector<vector<int>> res;
		for(auto &mat_row : mat){
			for(auto e : mat_row){
				if(res.empty() or res.back().size() == c)
					res.push_back({});
				res.back().push_back(e);
			}
		}
		return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		int m = mat.size(), n = mat.back().size();
		if(m * n != c * r) return mat;
		vector<vector<int>> res(r, vector<int>(c));
		int k = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				res[k/c][k%c] = mat[i][j];
				k++;
			}
		}
		return res;
    }
};

int main(){
}


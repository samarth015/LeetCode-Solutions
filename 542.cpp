#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int m, n;

		bool coordinates_within_matrix(int i, int j){
			return 0 <= i and i < m and 0 <= j and j < n;
		}

		int find_min_distance(vector<vector<int>>& mat, int i, int j){
			if(!mat[i][j]) return 0;

			int k = 1;
			while(k < n or k < m){
				for(int l = 0; l < k; l++){
					bool zero_found = (coordinates_within_matrix(i - l, j - k + l) and !mat[i - l][j - k + l])
									   or
									  (coordinates_within_matrix(i + l, j + k - l) and !mat[i + l][j + k - l]);
					if(zero_found) return k;
				}
				for(int l = 0; l < k; l++){
					bool zero_found = (coordinates_within_matrix(i - k + l, j + l) and !mat[i - k + l][j + l])
									   or
									  (coordinates_within_matrix(i + k - l, j - l) and !mat[i + k - l][j - l]);
					if(zero_found) return k;
				}
				k++;
			}

			return -1;
		}
			/*
			if(!mat[i][j]) return 0;
			int s = 1, le, ri, dw, up;
			le = ri = dw = up = -1;

			while(not (le == 0 and ri == (n-1) and dw == (m-1) and up == 0)){
				le = std::max(0, j - s);
				ri = std::min(n-1, j + s);
				up = std::max(0, i - s);
				dw = std::min(m-1, i + s);

				printf("%d %d %d %d\n", le, ri, dw, up);

				for(int k = 0; k < s; k++){
				}

				if(i - s > -1){
					for(int k = le; k <= ri; k++){
						if(!mat[up][k]) return (i - up) + abs(j - k);
					}
				}
				if(i + s < m){
					for(int k = le; k <= ri; k++){
						if(!mat[dw][k]) return (dw - i) + abs(j - k);
					}
				}
				if(j - s > -1){
					for(int k = up; k <= dw; k++){
						if(!mat[k][le]) return abs(i - k) + (j - le);
					}
				}
				if(j + s < n){
					for(int k = up; k <= dw; k++){
						if(!mat[k][ri]) return abs(i - k) + (ri - j);
					}
				}

				s++;
			}
			*/


	public:
		vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
			m = mat.size(), n = mat.front().size();
			vector<vector<int>> result (m ,vector<int>(n, -1));
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					result[i][j] = find_min_distance(mat, i, j);
				}
			}
			return result;
		}
};

int main(){
	vector<vector<int>> mat {{0,1,1,0},{0,1,1,0},{1,1,1,1},{1,0,1,0}};
	vector<vector<int>> di = Solution{}.updateMatrix(mat);

	cout << endl;
	cout << endl;
	for(auto ro : mat){
		for(auto col : ro) cout << col << ' ';
		cout << endl;
	}

	cout << endl;
	cout << endl;
	for(auto ro : di){
		for(auto col : ro) cout << col << ' ';
		cout << endl;
	}
	//Solution sol {};
	//sol.m = sol.n = 4;
	//cout << sol.find_min_distance(mat, 2, 2);
}

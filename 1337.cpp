#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
			int m = mat.size(), n = mat.back().size();
			vector<pair<int,int>> indices (m);
			for(int i = 0; i < m; i++){
				indices[i].first = i;
				int j = 0;
				while(j < n and mat[i][j]) indices[i].second++, j++;
			}
			sort(indices.begin(), indices.end(), [](auto a, auto b){
					if(a.second < b.second) return true;
					else if(a.second > b.second) return false;
					else return a.first < b.first;
					});
			vector<int> kind;
			for(int i = 0; i < k; i++) kind.push_back(indices[i].first);
			return kind;
		}
};

int main(){
}


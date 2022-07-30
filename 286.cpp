#include<bits/stdc++.h>
using namespace std;

class Solution {
	int m, n;

	bool indexIsValid(int i, int j){
		return 0 <= i and i < m and 0 <= j and j < n;
	}

public:
    void wallsAndGates(vector<vector<int>> &rooms) {

		const int max_int = numeric_limits<int>::max();
		m = rooms.size(), n = rooms.front().size();
		queue<pair<int,int>> q;

		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(rooms[i][j] == 0){
					q.push({i,j});
					rooms[i][j] = max_int;
				}
			}
		}

		int dist = 0;

		while(not q.empty()){
			int size = q.size();
			while(size--){
				auto ij = q.front();
				q.pop();
				int i = ij.first, j = ij.second;
				if(indexIsValid(i,j) and rooms[i][j] == max_int){
					rooms[i][j] = dist;
					q.push({i+1,j}); 
					q.push({i-1,j}); 
					q.push({i,j+1}); 
					q.push({i,j-1});
				}
			}
			dist++;
		}
    }
};

/*
[2147483647,-1,0,2147483647]
[2147483647,2147483647,2147483647,-1]
[2147483647,-1,2147483647,-1]
,[0,-1,2147483647,2147483647]

[3,-1,2147483647,2147483647]
[2,2147483647,2147483647,-1]
[1,-1,2147483647,-1]
[0,-1,2147483647,2147483647]
*/

int main(){
}


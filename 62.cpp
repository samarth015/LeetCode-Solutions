#include<bits/stdc++.h>
using namespace std;

// num of paths to arrive at dp[i][j] = dp[i-1][j] + dp[j-1][i]
// dp[i][0] = 1, dp[j][0] = 1   for all i and j
class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<int> memo_row(n, 1);

		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++){
				memo_row[j] = memo_row[j-1] + memo_row[j];
			}
		}

		return memo_row[n-1];
    }
};

class Solution2 {
	int m, n;
	unordered_map<int,int> memo;

	int isValidIndex(int i, int j){
		return 0 <= i and i < m and 0 <= j and j < n;
	}

	int findPaths(int i, int j){
		if(not isValidIndex(i,j)) return 0;
		if(i == m-1 or j == n-1) return 1;

		int idx = i*n+j;
		auto it = memo.find(idx);
		if(it == memo.end())
			it = memo.insert({idx, findPaths(i+1,j) + findPaths(i, j+1)}).first;

		return it->second;
	}
		
public:
    int uniquePaths(int m, int n) {
		this->m = m;
		this->n = n;
		return findPaths(0,0);
    }
};

int main(){
}


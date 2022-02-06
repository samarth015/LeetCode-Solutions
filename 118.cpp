#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> pastriangle(numRows, vector<int>{});
		pastriangle[0] = vector<int>{1};
		for(size_t i{0}; i < numRows - 1; i++){
			pastriangle[i+1].push_back(1);
			for(size_t j{1}; j < i + 1; j++)
				pastriangle[i+1].push_back( pastriangle[i][j-1] + pastriangle[i][j] );
			pastriangle[i+1].push_back(1);
		}
		return pastriangle;
    }
};

int main(){
}


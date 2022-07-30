#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		unordered_map<int, vector<int>> groups;
		vector<vector<int>> res {};
		for(int i = 0; i < groupSizes.size(); i++){
			groups[ groupSizes[i] ].push_back(i);
			if(groups[ groupSizes[i] ].size() == groupSizes[i]){
				res.push_back( move( groups[ groupSizes[i] ] ) );
				groups[ groupSizes[i] ] = vector<int>{};
			}
		}
		return res;
    }
};

int main(){
}


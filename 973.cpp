#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		vector<pair<int, vector<int>>> dispoints {};
		for(auto p : points) dispoints.push_back( {p[0]*p[0] + p[1]*p[1], p} );
		std::sort(dispoints.begin(), dispoints.end(), [](auto& a, auto& b){ return a.first < b.first; } );
		vector<vector<int>> closest {};
		for(int i = 0; i < k; i++) closest.push_back(dispoints[i].second);
		return closest; 
    }
};

int main(){
}


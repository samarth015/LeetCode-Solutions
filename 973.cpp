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

class Solution2 {
	private:
		class comp{
			public:
				bool operator() (pair<int, vector<int>> a, pair<int, vector<int>> b){
					return a.first < b.first;
				}
		};

		int distance_squared(vector<int> p){
			return p[0]*p[0] + p[1]*p[1];
		}

	public:
		vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
			vector<pair<int, vector<int>>> dispoints {};

			for(auto p : points) dispoints.push_back( make_pair(distance_squared(p), p) );

			priority_queue< pair<int, vector<int>>, vector< pair<int, vector<int>> >, comp> pq;
			for(auto point : dispoints){
				pq.push( move(point) );
				if(pq.size() > k) pq.pop();
			}

			vector<vector<int>> closest {};
			while(! pq.empty() ){
				closest.push_back(move( pq.top().second ));
				pq.pop();
			}
			return closest; 
		}
};

int main(){
}


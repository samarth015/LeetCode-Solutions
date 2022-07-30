#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
		sort(costs.begin(), costs.end(), [](auto &a, auto &b){ return a[1] - a[0] > b[1] - b[0]; });
		int mincost = 0;
		for(int i = 0; i < costs.size() / 2; i++)
			mincost += costs[i][0] + costs[i + costs.size() / 2 ][1];
		return mincost;
    }
};

bool cmp(vector<int> &a, vector<int> &b){
	int adiff = max(a[0], a[1]) - min(a[0], a[1]);
	int bdiff = max(b[0], b[1]) - min(b[0], b[1]);
	return adiff > bdiff;
}

class Solution2 {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
		sort(costs.begin(), costs.end(), cmp);
		int a, b, mincost = 0, n = costs.size() / 2;
		a = b = n;
		int i = 0;
		while( a and b ){
			auto& cost = costs[i];
			if(cost[0] < cost[1]){
				mincost += cost[0];
				a--;
			}
			else if(cost[0] > cost[1]){
				mincost += cost[1];
				b--;
			}
			else{
				mincost += cost[0];
				if(a < b) a--;
				else b--;
			}
			i++;
		}
		while(a) mincost += costs[i][0], i++, a--; 
		while(b) mincost += costs[i][1], i++, b--; 
		return mincost;
    }
};

int main(){
}


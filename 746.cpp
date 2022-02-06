#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<int>* cost;

		int minCostClimbingStairs(int pos){
			if(pos >= (*cost).size()) return 0;
			else return (*cost)[pos] + min( minCostClimbingStairs(pos + 1), minCostClimbingStairs(pos + 2) );
		}

	public:

		int minCostClimbingStairs(vector<int>& cost) {
			this->cost = &cost;
			return min( minCostClimbingStairs(0), minCostClimbingStairs(1));
		}
};

int main(){
}


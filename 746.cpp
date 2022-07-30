#include<bits/stdc++.h>
using namespace std;

// f(n) here is the min cost starting at -->   N
// f(n) = cost[n] + min(f(n-1),f(n-2))
class Solution4 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		int a = 0, b = 0, c; 
		while(n--){
			c = cost[n-1] + min(a,b);
			b = a;
			a = c;
			n--;
		}
		return min(a,b);
    }
};

// f(n) here is the min cost starting at -->   N OR N-1
// f(n) = min(cost[n]+f(n-1), cost[n-1] + f(n-2))
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		int a = 0, 
			b = min(cost[n-1], cost[n-2]), 
			c;
		if(cost.size() == 2) return b;
		n -= 3;
		while(n >= 0){
			c = min(cost[n] + b, cost[n+1] + a);
			a = b;
			b = c;
			n--;
		}
		return c;
    }
};

// top bottom memo
class Solution2 {
	private:
		vector<int>* cost;
		unordered_map<int,int> memo;

		int minCostClimbingStairs(int pos){
			if(memo.find(pos) == memo.end())
				memo[pos] = (*cost)[pos] + min( minCostClimbingStairs(pos + 1), minCostClimbingStairs(pos + 2) );
			return memo[pos];
		}

	public:

		int minCostClimbingStairs(vector<int>& cost) {
			this->cost = &cost;
			int n = cost.size();
			memo[n] = memo[n+1] = 0;
			return min( minCostClimbingStairs(0), minCostClimbingStairs(1) );
		}
};

// TLE
// Recursive
class Solution3 {
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


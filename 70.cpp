#include<bits/stdc++.h>
using namespace std;

class Solution2 {
	public:
		int climbStairs(int n) {
			if(n <= 2) return n;
			int curr, prev = 2, pprev = 1; 
			for(int i = 2; i < n; i++){
				curr = prev + pprev;
				pprev = prev;
				prev = curr;
			}
			return curr;
		}
};

// bottom-up memo
class Solution {
	private:
		vector<int> steps;
	public:
		Solution(): steps(46) {
			steps[0] = 0, steps[1] = 1, steps[2] = 2;
			for(int i{3}; i < 46; i++) steps[i] = steps[i-1] + steps[i-2];
		}

    int climbStairs(int n) {
		return steps[n];
    }
};

// top-bottom memo
class Solution4 {
	private:
		vector<int> steps;

	public:
		Solution4(): steps(46, 0) {
			steps[1] = 1;
			steps[2] = 2;
		}

		int climbStairs(int n) {
			if(steps[n] == 0) 
				steps[n] = climbStairs(n-1) + climbStairs(n-2);
			return steps[n];
		}
};

// Recursive
class Solution3 {
	public:
		int climbStairs(int n) {
			if(n < 2) return 1;
			return climbStairs(n-1) + climbStairs(n-2);
		}
};

int main(){
	Solution4 sol;
	for(int i = 0; i < 50; i++){
		cout << sol.climbStairs(i) << endl;
	}
}


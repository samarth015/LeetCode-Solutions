#include<bits/stdc++.h>
using namespace std;

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

int main(){
}


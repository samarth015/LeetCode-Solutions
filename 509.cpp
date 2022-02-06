#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<int> terms;

	public:
		Solution(): terms(31) {
			terms[0] = 0, terms[1] = 1;
			for(int i{2}; i < 31; i++) terms[i] = terms[i-1] + terms[i-2];
		}

		int fib(int n) {
			return terms[n];
		}
};

class Solution2 {
	public:
		int fib(int n) {
			int curr {0}, next{1}, tmp;
			for(int i{0}; i < n; i++){
				tmp = next;
				next = curr + next;
				curr = tmp;
			}
			return curr;
		}
};

int main(){
}

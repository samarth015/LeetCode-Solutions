#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<int> terms;
	public:
		Solution(): terms(38) {
			terms[0] = 0, terms[1] = terms[2] = 1;
			for(int i{3}; i < 38; i++) terms[i] = terms[i-1] + terms[i-2] + terms[i-3];
		}
		int tribonacci(int n) {
			return terms[n];
		}
};

class Solution2 {
	public:
		int tribonacci(int n) {
			int a = 0, b = 1, c = 1, tmp;
			for(int i{0}; i < n; i++){
				tmp = a + b + c;
				a = b;
				b = c;
				c = tmp;
			}
			return a;
		}
};

int main(){
}


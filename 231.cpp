#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		/*
		bool isPowerOfTwo(int n){
			long long p = 1;
			while(p < n) p = p << 1;
			return p == n;
		}
		*/
		bool isPowerOfTwo(int n){
			return n > 0 and ( not( n & (n-1) ) );
		}
};

int main(){
	cout << isPowerOfTwo(-1
}

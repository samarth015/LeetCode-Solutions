#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isPalindrome(int x) {
			if(x < 0) return false;
			int n = x, rev_n = 0;
			while(n)
				rev_n = rev_n*10 + n%10, n /= 10;
			return rev_n == x;
		}
};

int main(){
}

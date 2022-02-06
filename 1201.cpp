#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int nthUglyNumber(int n, int a, int b, int c) {
			int cnt = 0, num = 0;
			while(cnt != n){
				num++;
				cnt += num % a == 0 || num % b == 0 || num % c == 0;
				cout << num << ' ' << cnt<<  endl;
			}
			return num;
		}
};

class Solution2 {
	public:
		int nthUglyNumber(int n, int a, int b, int c) {
			int a_mul{a}, b_mul{b}, c_mul{c}, curr_ugly;
			for(int i = 1; i <= n; i++){
				curr_ugly = min({ a_mul, b_mul, c_mul });
				cout << curr_ugly << endl;
				if(a_mul == curr_ugly) a_mul += a;
				if(b_mul == curr_ugly) b_mul += b;
				if(c_mul == curr_ugly) c_mul += c;
			}
			return curr_ugly;
		}
};


int main(){
	cout << Solution{}.nthUglyNumber( 1000000000, 2, 217983653, 336916467 );
}


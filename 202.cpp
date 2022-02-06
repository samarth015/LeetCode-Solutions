#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int digitSquaredSum(int n){
			int sum {0};
			while(n){
				sum += pow(n%10, 2);
				n /= 10;
			}
			return sum;
		}

	public:
		bool isHappy(int n) {
			int fast{ digitSquaredSum(n) }, slow{n};
			while(n != 1){
				cout << slow << ' ' << fast << endl;
				if(fast == slow) return false;
				fast = digitSquaredSum(digitSquaredSum(n));
				slow = digitSquaredSum(n);
			}
			return true;
		}
};

int main(){
	cout << Solution{}.isHappy(19);
}


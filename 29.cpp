// try to think of an original division algo using bits maybe
// read restoring division on geeksforgeeks
// implement restoring div and long div( paper div ), euclidean division


#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int divide(long dividend, long divisor) {
                        if(dividend == -2147483648 and divisor == -1) return 2147483647;

			bool result_is_neg = (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0);
			dividend = dividend < 0 ? -dividend : dividend;
			divisor  = divisor  < 0 ? -divisor : divisor;

			while((dividend & 1) == 0 and (divisor & 1) == 0) dividend >>= 1, divisor >>= 1;

			long multiple = 0, quotient = 0;
			while(dividend >= multiple + divisor){
				multiple += divisor;
				quotient++;
			}

			return result_is_neg ? -quotient : quotient;
		}
};

int main(){
	cout << Solution{}.divide( 2147483647, 2) << endl;
}

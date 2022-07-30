#include<bits/stdc++.h>
using namespace std;

// f(n) = no( a..... ) + no( e.... ) ...
// f(n, 5) = f(n - 1, 5) + f(n-1, 4) + f(n-1, 3) .... 
// f(n, 1) = 1
// f(1, m) = m

class Solution {
private:
	int countVowelStringsHelper(int n, int m){
		if(m == 1) return 1;
		if(n == 1) return m;
		int sum = 0;
		for(int i = 1; i <= m; i++) sum += countVowelStringsHelper(n - 1, i);
		return sum;
	}
public:
    int countVowelStrings(int n) {
		return countVowelStringsHelper(n, 5);
    }
};

int main(){
	for(int i = 1; i <= 33; i++) cout << Solution{}.countVowelStrings(i) << endl;
}

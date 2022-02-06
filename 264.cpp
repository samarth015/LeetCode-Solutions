#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
		vector<int> uglies;
		int a, b, c;
		int x2, x3, x5;
		a = b = c = 0;
		for(int i = 1; i <= n; i++){
			x2 = uglies[a] * 2, x3 = uglies[b] * 3, x5 = uglies[c] * 5;
			uglies.push_back(  min({x2, x3, x5}) );
			if(x2 == uglies.back()) a++;
			if(x3 == uglies.back()) b++;
			if(x5 == uglies.back()) c++;
		}
		return uglies.back();
    }
};

class Solution2 {
public:
    int nthUglyNumber(int n) {
		set<int> ugly_nums {1};
		int next;
		while(n--){
			next = (*ugly_nums.begin());
			ugly_nums.erase(ugly_nums.begin());
			ugly_nums.insert({next * 2, next * 3, next * 5});
		}
		return next;
	}
};

int main(){
	cout << Solution{}.nthUglyNumber(1352);
}


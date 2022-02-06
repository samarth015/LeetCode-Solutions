#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n){
		vector<int> counts(n);
		counts[0] = 0;
		for(int i = 0; i <= n; i++) counts[ i ] = counts[ i/2 ] + (i&1);
		return counts;
    }
};

// nlogn
class Solution2 {
public:
    vector<int> countBits(int n){
		vector<int> counts {};
		int cnt, num;
		for(int i{0}; i <= n; i++){
			cnt = 0, num = i;
			while(num > 0) {
				cnt += num & 1;
				num >>= 1;
			}
			counts.push_back(cnt);
		}
		return counts;
    }
};

int main(){
}


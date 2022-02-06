
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int hammingWeight(uint32_t n) {
			int count = 0;
			uint32_t p = 1;
			for(int i = 1; i <= 32; i++){
				count += bool(p & n);
				p = p << 1;
			}
			return count;
		}
};



int main(){
}

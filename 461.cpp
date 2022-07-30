#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
		int diff = x ^ y, res = 0;
		while(diff){
			res += diff & 1;
			diff >>= 1;
    }
		return res;
	}
};

int main(){
}



#include<bits/stdc++.h>
using namespace std;

bool isBadVersion(int n); //API is defined

class Solution {
	public:
		int firstBadVersion(int n) {
			if(isBadVersion(1)) return 1;
			int lo = 2, hi = n, mid;
			while(lo <= hi){
				mid = lo + (hi - lo)/2;
				if(isBadVersion(mid) and isBadVersion(mid-1)) hi = mid-1;
				else if(not( isBadVersion(mid) or isBadVersion(mid-1))) lo = mid+1;
				else return mid;
			}
			return mid;
		}
};

int main(){
}

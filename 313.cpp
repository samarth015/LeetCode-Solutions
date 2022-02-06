#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int nthSuperUglyNumber(int n, vector<int>& primes) {
			int Size = primes.size();
			vector<int> uglies {1}, prindx (Size, 0), next_prime_mul(Size, 0);
			for(int j = 1; j < n; j++){
				for(int i = 0; i < Size; i++) next_prime_mul[i] = uglies[ prindx[i] ] * primes[i];

				int next_ugly = next_prime_mul[0];
				for(int i = 1; i < Size; i++) 
					if(next_ugly > next_prime_mul[i])
						next_ugly = next_prime_mul[i];

				for(int i = 0; i < Size; i++) 
					if(next_prime_mul[i] == next_ugly) prindx[i]++;	

				uglies.push_back(next_ugly);
			}
			return uglies.back();
		}
};

int main(){
}


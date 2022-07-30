#include<bits/stdc++.h>
using namespace std;

class solution {
	public:
		int findmaximumxor(vector<int>& nums) {
			unsigned pow2 = 1;
			vector<int> biggest_powers_of_2;
			for(auto n: nums){
			}
			int maxxor = 0;
			for(auto n1 : biggest_powers_of_2)
				for(auto n2 : nums)
					maxxor = max(maxxor, n2 ^ n1);
			return maxxor;
		}
};

// TLE
class solution2 {
	public:
		int findmaximumxor(vector<int>& nums) {
			unsigned pow2 = 1;
			vector<int> biggest_powers_of_2;
			for(auto n: nums){
				if(n >= 2 * pow2){
					biggest_powers_of_2.clear();
					while(n >= 2*pow2) pow2 *= 2;
				}
				if((n & pow2) == pow2)
					biggest_powers_of_2.push_back(n);
			}
			int maxxor = 0;
			for(auto n1 : biggest_powers_of_2)
				for(auto n2 : nums)
					maxxor = max(maxxor, n2 ^ n1);
			return maxxor;
		}
};

int main(){
}


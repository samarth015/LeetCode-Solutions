
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int>& prices){
			int min_so_far = prices.front(), maxpro = 0;
			for(auto p : prices){
				if(min_so_far > p) min_so_far = p;
				else if(maxpro < p - min_so_far) maxpro = p - min_so_far;
			}
			return maxpro;
		}
		//bruteforce
		/*	
		int maxProfit(vector<int>& prices) {
			int maxpro = 0;
			for(int i = 0; i < prices.size() - 1; i++){
				for(int j = i + 1; j < prices.size(); j++)
					maxpro = std::max(maxpro, prices[j] - prices[i]);
			}
			return maxpro;
		}
		*/
};

int main(){
}

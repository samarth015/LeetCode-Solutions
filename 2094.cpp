#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
		vector<int> evens;
		for(auto digit : digits) if(digit % 2 == 0) evens.push_back(digit);
		set<int> triplets;
		for(auto even : evens)
			for(auto d1 : digits) 
				for(auto d2 : digits){
					int seq = d1 * 100 + d2 * 10 + even;
					if(seq >= 100 and !(d1 == d2 or d1 == even or even == d1)) triplets.insert(seq);
				}
		return {triplets.begin(), triplets.end()};
    }
};

int main(){
}


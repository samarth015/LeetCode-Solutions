#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
		vector<multiset<int>> nbits (log2(pow(10, 5)) + 1);
		for(auto n : arr) nbits[ __builtin_popcount(n) ].insert(n);
		vector<int> sorted {};
		for(auto bucket : nbits) sorted.insert(sorted.end(), bucket.begin(), bucket.end());
		return sorted;
    }
};

int main(){
}


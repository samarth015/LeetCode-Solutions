#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
		unordered_set<int> distinct_nums {};
		vector<int> dups {};
		for(auto n : nums){
			if(distinct_nums.find(n) != distinct_nums.end()) dups.push_back(n);
			else distinct_nums.insert(n);
		}
		return dups;
    }
};

int main(){
}


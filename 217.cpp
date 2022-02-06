#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> unst {};
		for(auto n : nums) {
			if(unst.find(n) != unst.end()) return true;
			else unst.insert(n);
		}
		return false;
    }
};

class Solution2 {
	public:
    bool containsDuplicate(vector<int>& nums) {
		return nums.size() != unordered_set<int>{nums.begin(), nums.end()}.size();
    }
};

int main(){
}


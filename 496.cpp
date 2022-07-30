#include<bits/stdc++.h>
using namespace std;

// Use monotonic stack to find next greater for each element and save it in a vector.
// Use unordered_set to map nums to indexes in that vector.
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		set<int> numset( nums2.begin(), nums2.end() );
		vector<int> res;
		for(auto n: nums1){
			auto next = (++numset.find(n));
			if(next 
			res.push_back(*);
		}
		
		return res;
    }
};

int main(){
}


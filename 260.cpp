#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		unordered_set<int> st {};
		for(auto n : nums){
			unordered_set<int>::iterator it;
			if((it = st.find(n)) != st.end()) st.erase(it);
			else st.insert(n);
    }
		return {st.begin(), st.end()};
};

int main(){
}




#include<bits/stdc++.h>
using namespace std;

//O(n) without extra space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> result(nums.size(), 1);
		int cumprod {1};
		for(int i = 1; i < nums.size(); i++){
			cumprod *= nums[i-1]; 
			result[i] = cumprod;
		}
		cumprod = 1;
		for(int i = nums.size() - 2; i >= 0; i--){
			cumprod *= nums[i + 1]; 
			result[i] *= cumprod;
		}
		return result;
    }
};

//O(n)
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		auto len {nums.size()};
		vector<int> l2r(len), r2l(len), result{};
		partial_sum(nums.begin(), nums.end(), l2r.begin(), [](auto &a, auto &b){ return a * b; });
		partial_sum(nums.rbegin(), nums.rend(), r2l.rbegin(), [](auto &a, auto &b){ return a * b; });
		result.push_back(r2l[1]);
		for(int i = 1; i < len - 1; i++) result.push_back( l2r[i-1] * r2l[i+1] );
		result.push_back(l2r[len-2]);
		return result;
    }
};

int main(){
	vector<int> v {1,2,3,4};
	for(auto b : Solution{}.productExceptSelf(v)) cout << b << ' ';
}


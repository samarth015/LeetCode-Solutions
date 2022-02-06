#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
		for(int i = 0; i < arr.size(); i++){
			for(int j = i + 1; j < arr.size(); j++){
				if(arr[j] == 2 * arr[i] or arr[i] == 2 * arr[j]) return true;
			}
		}
		return false;
    }
};

// why is this wrong?
class Solution2 {
public:
    bool checkIfExist(vector<int>& arr) {
		unordered_map<int, int> nums_and_2xnums {};
		unordered_set<int> unique_nums {arr.begin(), arr.end()};
		for(auto n : unique_nums) nums_and_2xnums[2*n]++, nums_and_2xnums[n]++;
		for(auto n : unique_nums) if(nums_and_2xnums[2*n] == 2) return true;
		return false;
    }
};

int main(){
}


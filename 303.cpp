#include<bits/stdc++.h>
using namespace std;

class NumArray {
	private:
    vector<int> cumsum;
    
public:
    NumArray(vector<int>& nums): cumsum(nums.size() + 1) {
		std::partial_sum(nums.begin(), nums.end(), cumsum.begin() + 1);
	}
    
    int sumRange(int left, int right) {
		return cumsum[right + 1] - cumsum[left];
	}
};

//linear time
class NumArray2 {
	private:
    vector<int> *nums;
    
public:
    NumArray(vector<int>& nums): nums{&nums} {}
    
    int sumRange(int left, int right) {
		int sum {0};
		while(left <= right){
			sum += (*nums)[left];
			left++;
		}
		return sum;
    }
};


int main(){
}


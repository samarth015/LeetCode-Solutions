#include<bits/stdc++.h>
using namespace std;

// Average case complexity O(n)
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
		nth_element(nums.begin(), nums.begin() + (k-1), nums.end(), greater<int>{});
		return nums[k-1];
    }
};

// Average case O(n) with QuickSelect implemented from scratch.
class Solution4 {
private:
	class quickSelect{
		private:
			vector<int> &nums;
			int k;

			int select(int l, int r){
				int pivot = nums[r], pindx = l;
				for(int i = l; i < r; i++){
					if(nums[i] <= pivot){
						swap(nums[i], nums[pindx]);
						pindx++;
					}
				}
				swap(nums[r], nums[pindx]);

				if(k < pindx) return select(l, pindx - 1);
				else if(k > pindx) return select(pindx + 1, r);
				else return nums[k];
			}

		public:
			quickSelect(vector<int> &nums, int k): nums{nums}, k{k} {}

			int operator ()(){
				return select(0, nums.size() - 1);
			}
	};

public:
	int findKthLargest(vector<int>& nums, int k) {
		k = nums.size() - k;
	 	return quickSelect{nums, k}();
	}
};

// n + klogn
class Solution3{
	public:
		int findKthLargest(vector<int>& nums, int k) {
			make_heap(nums.begin(), nums.end());   // max heap
			while(k-- > 1){
				pop_heap(nums.begin(), nums.end());
				nums.pop_back();
			}
			return nums.front();
		}
};

// nlogk
class Solution {
	public:
		int findKthLargest(vector<int>& nums, int k) {
			priority_queue<int, vector<int>, greater<int>> pq;   // min heap
			for(auto n: nums){
				pq.push(n);
				if(pq.size() > k) pq.pop();
			}
			return pq.top();
		}
};

int main(){
}


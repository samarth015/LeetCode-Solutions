#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freqmp {};
		for(auto n : nums) freqmp[n]++;
		vector<vector<int>> buckets (nums.size()+1);
		for(auto numfreq : freqmp) buckets[numfreq.second].push_back(numfreq.first);
		vector<int> kfreq{};
		int i = nums.size();
		while(k){
			for(auto n : buckets[i]){
				kfreq.push_back(n); k--;
				if(k == 0) break;
			}
			i--;
		}
		return kfreq;
    }
};

class Solution4{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freqmp {};
		for(auto n : nums) freqmp[n]++;
		vector<pair<int, int>> numsfreq (freqmp.begin(), freqmp.end());
		std::sort(numsfreq.begin(), numsfreq.begin() + k, [](auto &a, auto &b){ return a.second > b.second; });
		for(int i = k; i < numsfreq.size(); i++){
			if(numsfreq[i].second > numsfreq[k-1].second){
				std::swap(numsfreq[i], numsfreq[k-1]);
				int j = k - 2; 
				auto tmp = numsfreq[k-1];
				while(j >= 0 and numsfreq[j].second < tmp.second){
					numsfreq[j+1] = numsfreq[j];
					j--;
				}
				numsfreq[j+1] = tmp;
			}
		}
		vector<int> kfreq {};
		for(int i = 0; i < k; i++) kfreq.push_back( numsfreq[i].first );
		return kfreq;
    }
};

class Solution3 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		multimap<int, int> freqmp {};
		int i = 1, currnum = nums[0], currfreq{1};
		while(i < nums.size()){
			if(nums[i] == currnum) currfreq++;
			else {
				freqmp.insert({currfreq, currnum});
				currfreq = 1;
				currnum = nums[i];
			}
		}
		freqmp.insert({currfreq, currnum});
		vector<int> kfreq {};
		auto it = freqmp.rbegin();
		for(int i = 0; i < k; i++){
			kfreq.push_back( (*it).second );
			it++;
		}
		return kfreq;
    }
};

class Solution2{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freqmp {};
		for(auto n : nums) freqmp[n]++;
		vector<pair<int, int>> numsfreq (freqmp.begin(), freqmp.end());
		std::sort(numsfreq.begin(), numsfreq.end(), [](auto &a, auto &b){ return a.second > b.second; });
		vector<int> kfreq {};
		for(int i = 0; i < k; i++) kfreq.push_back( numsfreq[i].first );
		return kfreq;
    }
};

int main(){
}


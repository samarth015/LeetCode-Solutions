#include<bits/stdc++.h>
using namespace std;

// QuickSelect + Sort k elements. nm + kmlogk
// m - length of string
class Solution4{
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			unordered_map<string, int> freq;
			for(auto &word: words) freq[word]++;

			vector<pair<int, string>> pq;
			for(auto f: freq) pq.push_back({f.second, f.first});

			int n = pq.size();
			auto comp = [](auto &a, auto &b){
				if(a.first == b.first) return a.second < b.second;
				else return a.first > b.first;
			};

			nth_element(pq.begin(), pq.begin() + k, pq.end(), comp);
			sort(pq.begin(), pq.begin() + k, comp);

			vector<string> res;
			for(int i = 0; i < k; i++) res.push_back(pq[i].second);

			return res;
		}
};



// Sorting. nmlogn
class Solution3{
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			unordered_map<string, int> freq;
			for(auto &word: words) freq[word]++;
			vector<pair<int, string>> pq;
			for(auto f: freq) pq.push_back({f.second, f.first});
			sort(pq.begin(), pq.end(),
					[](auto &a, auto &b){
					if(a.first == b.first) return a.second < b.second;
					else return a.first > b.first;
					});
			vector<string> res;
			int n = pq.size();
			for(int i = 0; i < k; i++) res.push_back(pq[i].second);
			return res;
		}
};

// Min heap.  nmlogk
// Can also be solved using std::priority_queue like max heap solution
class Solution5{
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			unordered_map<string, int> freq;
			for(auto &word: words) freq[word]++;

			auto comp = [](auto &a, auto &b){
				if(a.first == b.first) return a.second < b.second;
				else return a.first > b.first;
			};

			vector<pair<int, string>> pq;
			for(auto f: freq){
				pq.push_back({f.second, f.first});
				push_heap(pq.begin(), pq.end(), comp); 
				if(pq.size() > k){
					pop_heap(pq.begin(), pq.end(), comp);
					pq.pop_back();
				}
			}

			vector<string> res(k);
			auto heapend = pq.end();
			while(k--){
				pop_heap(pq.begin(), heapend--, comp);
				res[k] = heapend->second;
			}
			return res;
		}
};

// Max heap
class Solution2 {
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			unordered_map<string, int> freq;
			for(auto &word: words) freq[word]++;

			vector<pair<int, string>> v;
			for(auto f: freq) v.push_back({f.second, f.first});

			auto comp = [](auto &a, auto &b){
				if(a.first == b.first) return a.second > b.second;
				else return a.first < b.first;
			};

			using type = pair<int, string>;
			priority_queue<type, vector<type>, function<bool(type&, type&)>> pq (comp, move(v)); 
										//This will also work			     pq (v.begin(), v.end(), comp); 
						// You could have also not made the vector at all and directly filled pq with freq's range.

			vector<string> res;
			while(k--){
				res.push_back(pq.top().second);
				pq.pop();
			}
			return res;
		}
};


// bucket sort   
// Average case - O(nm)
// Worst case - All characters have the same frequency and u have to now sort N elements.
// O(nmlogn)
class Solution {
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			unordered_map<string, int> freq;
			for(auto &word: words) freq[word]++;

			vector<vector<string>> buckets(words.size()+1);
			for(auto &worfreq: freq)
				buckets[worfreq.second].push_back(worfreq.first);

			vector<string> res;
			for(int i = words.size(); i >= 0; i--){
				auto &bucket = buckets[i];
				if(not bucket.empty()){
					sort(bucket.begin(), bucket.end());
					for(auto &word: buckets[i]){
						res.push_back(word);
						if(--k == 0) return res;
					}
				}
			}
			return res;
		}
};

int main(){
	vector<string> strs {"the","day","is","sunny","the","the","the","sunny","is","is" };
	auto res = Solution5{}.topKFrequent(strs, 3);
	for(auto i: res) cout << i << endl;
}


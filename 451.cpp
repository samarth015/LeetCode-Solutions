#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
		vector<vector<char>> buckets (s.size() + 1);
		vector<int> frequencies (128, 0);
		for(auto ch : s) frequencies[ch]++;
		for(int ch = 0; ch < 127; ch++) if(frequencies[ch]) buckets[frequencies[ch]].push_back(ch);
		string res {};
		for(int i = buckets.size() - 1; i >= 0; i--)
			for(int j = 0; j < i; j++)
				for(auto ch : buckets[i]) res.push_back(ch);
		return res;
    }
};

int main(){
}


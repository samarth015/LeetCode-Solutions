#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {

			vector<pair<string, int>> strsi;
			for(int i = 0; i < strs.size(); i++)
				strsi.emplace_back(strs[i], i);
				
			for(auto &si: strsi) sort(si.first.begin(), si.first.end());

			sort(strsi.begin(), strsi.end(), [](auto &a, auto &b)
											   {return a.first < b.first;});

			vector<vector<string>> res {{strs[strsi[0].second]}};
			string prev = strsi[0].first;
			for(int i = 1; i < strsi.size(); i++){
				if(strsi[i].first != prev) {
					res.push_back({});
					prev = strsi[i].first;
				}
				res.back().push_back(strs[strsi[i].second]);
			}

			return res;
		}
};

class Solution2 {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs){
			unordered_map<string, vector<string>> anagram_map;
			for(auto &s: strs){
				string str = s;
				sort(str.begin(), str.end());
				anagram_map[str].push_back(s);
			}
			vector<vector<string>> res;
			for(auto& pr : anagram_map){
				res.push_back(move(pr.second));
			}
			return res;
		}
};


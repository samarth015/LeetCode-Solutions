#include<bits/stdc++.h>
using namespace std;

class Solution3 {
	vector<vector<string>> result;
	vector<string> curr;

	bool ispalin(string &s){
		return s == string(s.rbegin(), s.rend());
	}

	void partition(int i, string &s){
		if(i == s.size()){
			if(ispalin(curr.back()))
				result.push_back(curr);
			return;
		}

		char c = s[i];

		curr.back().push_back(c);
		partition(i+1, s);
		curr.back().pop_back();

		if(ispalin(curr.back())){
			curr.push_back(string{c});
			partition(i+1, s);
			curr.pop_back();
		}
		
	}

public:
    vector<vector<string>> partition(string s) {
		result = vector<vector<string>>{};
		curr = vector<string>{string{s[0]}};
		partition(1,s);
		return result;
    }
};

class Solution2 {
	bool ispalin(string &s){
		return s == string(s.rbegin(), s.rend());
	}

public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> parts {{string{s[0]}}};
		for(int i = 1; i < s.size(); i++){
			vector<vector<string>> tmp;
			char c = s[i];
			for(auto part: parts){
				if(ispalin(part.back())){
					part.push_back(string{c});
					tmp.push_back(part);
					part.pop_back();
				}
				part.back().push_back(c);
				tmp.push_back(part);
			}
			parts = tmp;
		}

		auto new_end = remove_if(parts.begin(), parts.end(), 
				[&](auto &part){
					return !ispalin(part.back());
				});
		parts.erase(new_end, parts.end());

		return parts;
    }
};

// First find all possible ways to partition the string
// then remove all ways where any substr is not palin.
class Solution1 {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> parts {{string{s[0]}}};
		for(int i = 1; i < s.size(); i++){
			vector<vector<string>> tmp;
			char c = s[i];
			for(auto part: parts){
				part.push_back(string{c});
				tmp.push_back(part);
				part.pop_back();
				part.back().push_back(c);
				tmp.push_back(part);
			}
			parts = tmp;
		}

		auto notPalin = [](string &ss){
			return ss != string(ss.rbegin(), ss.rend());
		};
		
		auto predicate = [notPalin](auto part) {
							return any_of(part.begin(), part.end(), notPalin);
		};

		auto new_end = remove_if(parts.begin(), parts.end(), predicate);
		parts.erase(new_end, parts.end());
		return parts;
    }
};

int main(){
}


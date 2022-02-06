#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		std::unordered_map<char, string> mp;
	public:
		Solution(): mp { {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz" } } {} 

		vector<string> letterCombinations(string digits) {
			if(digits.empty()) return {};
			vector<string> combs{""}, tmp{};
			for(size_t i{0}; i < digits.size(); i++){
				for(auto ch : mp[ digits[i] ]){
					for(auto comb : combs) tmp.push_back(comb + ch);
				}
				combs = std::move(tmp);
				tmp = vector<string>{};
			}
			return combs;
		}
};

class Solution2 {
	private:
		std::unordered_map<char, string> mp;
		string *digits;

		vector<string> letterCombinations(int pos){
			if(pos == (*digits).size()){
				return vector<string> {""};
			}
			else {
				auto remaining_combs { letterCombinations(pos + 1) };
				vector<string> all_combs {};
				for(auto ch : mp[ (*digits)[pos] ] )
					for(auto comb : remaining_combs) 
						all_combs.push_back( ch + string{comb} ); 
				return all_combs;
			}

		}

	public:
		Solution2(): mp { {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz" } } {} 

		vector<string> letterCombinations(string digits) {
			if(digits.empty()) == 0) return {};
			this->digits = &digits;
			return letterCombinations(0);
		}
};

int main(){
	for(auto comb : Solution2{}.letterCombinations("23")) cout << comb << ' ';
}


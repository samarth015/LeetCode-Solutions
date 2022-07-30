#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
		bool inside = false;
		vector<string> words;
		string word;
		int ws{};
		for(char c : text){
			inside = c != ' ';
			ws += !inside;
			if(inside) word.push_back(c);
			else if(!inside and !word.empty()){
				words.push_back(move(word));
				word = "";
			}
		}
		if(!word.empty()) words.push_back(move(word));
		if(words.size() == 1) return words.back() + string(ws, ' ');
		int sep_sp = ws / (words.size()-1);
		int ending_sp = ws % (words.size()-1);
		string res;
		for(int i = 0; i < words.size() - 1; i++)
			res += words[i] + string(sep_sp, ' ');

		res += words.back() + string(ending_sp, ' ');
		return res;
    }
};

int main(){
}


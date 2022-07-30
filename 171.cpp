#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	array<int, 7> posval;
	map<char, int> keymap;

public:
	Solution(): posval{}, keymap{} {
		int curr_val = 1;
		for(int i = 0; i < 7; i++){
			curr_val *= 26; 
			posval[i] = curr_val;
		}
		for(int i = 0; i < 26; i++){
			keymap['A' + i] = i + 1;
		}
	}

    int titleToNumber(string columnTitle) {
		reverse(columnTitle.begin(), columnTitle.end());
		int result = 0;
		for(int i = 0; i < columnTitle.size(); i++){
			char letter = columnTitle[i];
			result += keymap[letter] * posval[i];
		}
		return result;
    }
};

int main(){
}


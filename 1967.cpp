#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
		int res = 0;
		for(auto pattern : patterns) if(word.find(pattern) != string::npos) res++;
		return res;
    }
};

int main(){
}

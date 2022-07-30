#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool digitCount(string num) {
		unordered_map<int, int> digcounts;
		for(size_t i = 0; i < num.size(); i++) digcounts[num[i]-'0']++;
		for(size_t i = 0; i < num.size(); i++) if(num[i] - '0' != digcounts[i]) return false;
		return true;
    }
};

int main(){
	for(size_t i = 0; i < 10000000000; i++) if(Solution{}.digitCount(to_string(i))) cout << i << endl;
}


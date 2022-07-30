#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string encode(vector<string> &strs) {
			string encoded;
			for(string &s: strs){
				encoded += to_string(s.size()) + '#' + s;
			}
			return encoded;
		}

		vector<string> decode(string &str) {
			vector<string> decoded;
			int i = 0, start = 0, n = str.size();
			while(i < n){
				if(str[i] == '#'){ 
					int len = stoi( string(str.begin() + start, str.begin() + i));
					i += 1;
					decoded.emplace_back(str.begin()+i, str.begin()+i+len);
					start = i = i + len;
				}
				else{
					i += 1;
				}
			}
			return decoded;
		}
};

int main(){
}


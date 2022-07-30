#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
		int depth = 0;
		for(auto oper : logs){
			if(oper[0] == '.'){
				if(oper[1] == '.' and depth > 0) depth--;
			}
			else{
				depth++;
			}
		}
		return depth;
    }
};

int main(){
}


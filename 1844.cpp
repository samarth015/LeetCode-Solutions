#include<bits/stdc++.h>
using namespace std;

char shift(char c, int x){
	return c + x;
}

class Solution {
public:
    string replaceDigits(string s) {
		for(int i = 1; i < s.size(); i += 2) s[i] = shift(s[i-1], s[i] - '0');
		return s;
    }
};

int main(){
	cout << Solution{}.replaceDigits("a1b2c3d4e");
}


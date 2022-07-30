#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number(int num){
		auto nstr = std::to_string(num);
		auto pos { nstr.find('6') };
		if(pos != string::npos) nstr[pos] = '9';
		return stoi(nstr);
    }
};

int main(){
}


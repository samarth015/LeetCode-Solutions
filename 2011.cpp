
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations){
		int X{};
		for(auto oper : operations)
			X += oper[1] == '+' ? 1 : -1;
		return X;
    }
};

int main(){
}

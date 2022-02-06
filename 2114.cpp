#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
		int maxcnt {0}, cnt;
		for(auto &sentence : sentences){
			cnt = std::count(sentence.begin(), sentence.end(), ' ');
			if(maxcnt > cnt) maxcnt = cnt;
		}
		return maxcnt + 1;
    }
};

int main(){
}


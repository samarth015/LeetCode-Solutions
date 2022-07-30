#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int calPoints(vector<string>& ops) {
			vector<int> scores;
			for(auto op : ops){
				if(op[0] == 'C') scores.pop_back();
				else{
					int new_score;
					if(op[0] == '+') new_score = scores.back() + *(scores.end() - 2);
					else if(op[0] == 'D') new_score = 2*scores.back();
					else new_score = stoi( op );
					scores.push_back(new_score);
				}
			}
			return accumulate(scores.begin(), scores.end(), 0);
		}
};


int main(){
}


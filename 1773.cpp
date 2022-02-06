#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue){
			int count = 0;
			for(auto &item: items){
				if(( ruleKey == "type" and ruleValue == item[0] ) or 
						( ruleKey == "color" and ruleValue == item[1] ) or 
						( ruleKey == "name" and ruleValue == item[2] )) 
					count++;
			}
			return count;
		}
};

int main(){
}

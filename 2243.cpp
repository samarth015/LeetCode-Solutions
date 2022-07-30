#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
		while(k < s.size()){
			string new_s;
			int n = 0, group_sum = 0;
			for(int i = 0; i < s.size(); i++){
				group_sum += s[i] - '0';
				n++;
				if(n == k){
					new_s += to_string(group_sum);
					group_sum = 0;
					n = 0;
				}
			}
			if(n) new_s += to_string(group_sum);
			s = new_s;
		}
		return s;
    }
};

int main(){
}


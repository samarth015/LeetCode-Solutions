#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
		string transformed_s;
		for(auto ch : s) transformed_s += to_string(ch - 'a' + 1);
		cout << transformed_s;
		long long num = atoll( transformed_s.c_str() );
		cout << num;

		while(num >= 10 and k--){
			long long new_num = 0;
			while(num){
				new_num += num % 10;
				num /= 10;
			}
			num = new_num;
		}

		return num;
    }
};

int main(){
	cout << Solution{}.getLucky("leetcode", 2);
}


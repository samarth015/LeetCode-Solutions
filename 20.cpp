#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		bool is_opening(char c){
			return c == '(' or c == '{' or c == '[';
		}

		char corresponding_closing(char c){
			if(c == '(') return ')';
			else if( c == '{' ) return '}';
			else return ']';
		}

	public:
		bool isValid(string s) {
			stack<char> st;
			for(auto c: s){
				if(is_opening(c)) st.push(corresponding_closing(c));
				else {
					if(st.empty() or st.top() != c) return false;
					else st.pop();
				}
			}
		return st.empty();
		}
};


int main(){
}


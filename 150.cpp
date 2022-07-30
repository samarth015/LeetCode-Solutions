#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	int binary_operation(int lhs, char oper, int rhs){
		switch(oper) {
			case '+': return lhs + rhs;
			case '-': return lhs - rhs;
			case '*': return lhs * rhs;
			case '/': return lhs / rhs;
		}
		return 0;
	}
public:
    int evalRPN(vector<string>& tokens) {
		string opers = "+-*/";
		stack<int> st;

		for(auto &token: tokens){
			if(token.size() == 1 and opers.find(token[0]) != string::npos){
			
				int rhs = st.top(); st.pop();
				int lhs = st.top(); st.pop();
				char oper = token[0];

				st.push( binary_operation(lhs, oper, rhs) );
			}
			else{
				st.push(stoi( token ));
			}
		}
		return st.top();
	}
};

int main(){
}


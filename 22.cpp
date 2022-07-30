#include<bits/stdc++.h>
using namespace std;

// Recursive solution
// left and right represent remaining opening and closing braces to add.
class Solution2{
	vector<string> answers;
	void collect(string comb, int left, int right){
		if(left == 0) answers.push_back(comb+string(')', right));
		else if(right == 0) collect(comb + '(', left-1, right+1);
		else collect(comb + '(', left-1, right+1), collect(comb+')', left, right-1);
	}

public:
    vector<string> generateParenthesis(int n) {
		answers = vector<string>{};
		collect("", n, 0);
		return answers;
    }
};

// Stack
class Solution3{
public:
    vector<string> generateParenthesis(int n) {
		stack<tuple<string, int, int>> st {};
		vector<string> res;
		st.push(make_tuple("", n, 0));
		while(not st.empty()){
			auto &tup = st.top();
			st.pop();
			string expr = get<0>(tup);
			int left = get<1>(tup);
			int right = get<2>(tup);
			if(left == 0) {
				res.push_back(expr + string(right, ')'));
			}
			else if(right == 0) {
				st.push( make_tuple(expr+'(', left-1, right+1) );
			}
			else{
				st.push( make_tuple(expr+'(', left-1, right+1) );
				st.push( make_tuple(expr+')', left, right-1) );
			}
		}
		return res;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<tuple<string, int, int>> v { {"(", 1, 0} };
		for(int i = 1; i < n * 2; i++){
			vector<tuple<string, int, int>> tmp;
			for(auto tup: v){
				string expr = move(get<0>(tup));
				int opens = get<1>(tup);
				int closes = get<2>(tup);
				if(opens == n){
					tmp.push_back({expr + ')', opens, closes + 1});
				}
				else if(closes == opens){
					tmp.push_back({expr + '(', opens + 1, closes});
				}
				else{
					tmp.push_back({expr + ')', opens, closes + 1});
					tmp.push_back({expr + '(', opens + 1, closes});
				}
			}
			v = move(tmp);
		}
		vector<string> res;
		for(auto tup: v) res.push_back(move(get<0>(tup)));
		return res;
    }
};

int main(){
}


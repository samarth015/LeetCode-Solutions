#include<bits/stdc++.h>
using namespace std;

// stack
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
        stack<int> indx;
		vector<int> res(n);
        for(int i = 0; i < n; i++){
			while(!indx.empty() and temperatures[i] > temperatures[indx.top()]){
				int j = indx.top();
				indx.pop();
				res[j] = i-j;
			}
			indx.push(i);
        }
		return res;
    }
};

// Jumps to the next larger element
class Solution3 {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> res(temperatures.size());
		for(int i = temperatures.size()-1; i >= 0; i--){
			int j = i+1;
			while(j < temperatures.size() and temperatures[i] >= temperatures[j]){
				if(res[j] > 0) j += res[j];
				else j = temperatures.size();
			}
			if(j != temperatures.size()) res[i] = j - i;
		}
		return res;
    }
};

//TLE
//brute force
class Solution2 {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> res;
		for(int i = temperatures.size() - 1; i >= 0; i--){
			int j;
			for(j = i + 1; j < temperatures.size(); j++){
				if(temperatures[j] > temperatures[i]){
					res.push_back(j-i);
					break;
				}
			}
            if(j == temperatures.size()) res.push_back(0);
		}
		return res;
    }
};

int main(){
}


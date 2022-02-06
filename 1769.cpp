#include<bits/stdc++.h> 
using namespace std;


// most elegant. LTR RTL
class Solution {
	public:
		vector<int> minOperations(string boxes) {
			vector<int> res (boxes.size());

			int cnt = 0, ops = 0;
			for(int i = 0; i < boxes.size(); i++){
				ops += cnt;
				res[i] = ops;
				if(boxes[i] == '1') cnt++;
			}
			
			cnt = ops = 0;
			for(int i = boxes.size() - 1; i >= 0; i--){
				ops += cnt;
				res[i] += ops;
				if(boxes[i] == '1') cnt++;
			}

			return res;
		}
};

//linear time
class Solution {
	public:
		vector<int> minOperations(string boxes) {

			int left_ones{0}, right_ones{0};
			vector<int> res (boxes.size());

			for(int i = 0; i < boxes.size(); i++){
				if(boxes[i] == '1'){
					right_ones++;
					res[0] += i;
				}
			}

			for(int i = 1; i < boxes.size(); i++){
				if(boxes[i-1] == '1') left_ones++, right_ones--;
				res[i] = res[i-1] + left_ones - right_ones;
			}

			return res;
		}
};

//brute force
class Solution {
	public:
		vector<int> minOperations(string boxes) {
			vector<int> res (boxes.size());
			for(int i = 0; i < boxes.size(); i++){
				int moves_req {};
				for(int n = 0; n < i; n++) moves_req += (i - n) * (boxes[n] == '1'); 
				for(int n = i+1; n < boxes.size(); n++) moves_req += (i - n) * (boxes[n] == '1'); 
				res[i] = moves_req;
			}
			return res;
		}
};

int main(){
}


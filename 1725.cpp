#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
		int maxlen{0};
		for(auto rect: rectangles){
			int sqlen = min(rect[0], rect[1]);
			if(sqlen > maxlen) maxlen = sqlen;
		}
		int cnt = 0;
		for(auto rect: rectangles) cnt += (rect[0] >= maxlen and rect[1] >= maxlen);
		return cnt;
    }
};

int main(){
}


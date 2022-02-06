#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int x, y;
		bool isvalid(vector<int>& point){
			return x == point[0] or y == point[1];
		}
		int manhattan(vector<int>& point){
			return abs(x - point[0]) + abs(y - point[1]);
		}
	public:
		int nearestValidPoint(int x, int y, vector<vector<int>> points) {
			this->x = x;
			this->y = y;

			int i = 0, smind{-1}, smdis = { numeric_limits<int>::max() }, curr_dis;
			while(i < points.size()){
				if(isvalid(points[i])){
					curr_dis = manhattan(points[i]);
					if(curr_dis < smdis){
						smdis = curr_dis;
						smind = i;
					}
				}
				i++;
			}
			return smind;
		}
};

int main(){
	cout << Solution{}.nearestValidPoint(3, 4, {{1,2},{3,1},{2,4},{2,3},{4,4}});
}

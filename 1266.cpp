#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int min_time_between_points(int x1, int y1, int x2, int y2){
			int dx = abs(x1 - x2), dy = abs(y1 - y2);
			return max(dx, dy);
		}
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int time = 0;
		for(int i = 0; i < points.size() - 1; i++){
			time += min_time_between_points(points[i-1][0], points[i-1][1], points[i][0], points[i][1]);
		}
		return time;
    }
};

int main(){
}


#include<bits/stdc++.h>
using namespace std;

// Monotonic stack
class Solution {
	public:
		int carFleet(int target, vector<int>& position, vector<int>& speed) {
			int n = speed.size();
			vector<pair<int, int>> pospeed;
			for(int i = 0; i < n; i++) 
				pospeed.emplace_back(position[i], speed[i]);

			auto comp = [] (auto a, auto b){ return a.first < b.first; };
			sort(pospeed.begin(), pospeed.end(), comp);

			vector<double> time(n);
			for(int i = 0; i < n; i++)
				time[i] = static_cast<double>(target - pospeed[i].first) / pospeed[i].second;

			stack<double> st;
			for(int i = 0; i < n; i++){
				while(not st.empty() and st.top() <= time[i])
					st.pop();
				st.push(time[i]);
			}

			return st.size();
		}
};

// 2 variables
class Solution2 {
	public:
		int carFleet(int target, vector<int>& position, vector<int>& speed) {
			int n = speed.size();
			vector<pair<int, int>> pospeed;
			for(int i = 0; i < n; i++) 
				pospeed.emplace_back(position[i], speed[i]);

			auto comp = [] (auto a, auto b){ return a.first < b.first; };
			sort(pospeed.begin(), pospeed.end(), comp);

			vector<double> time(n);
			for(int i = 0; i < n; i++)
				time[i] = static_cast<double>(target - pospeed[i].first) / pospeed[i].second;

			double ahead_fleet_time = numeric_limits<double>::min();
			int cnt = 0;
			for(int i = n-1; i >= 0; i--){
				if(ahead_fleet_time < time[i]){
					cnt++;
					ahead_fleet_time = time[i];
				}
			}

			return cnt;
		}
};

int main(){
}


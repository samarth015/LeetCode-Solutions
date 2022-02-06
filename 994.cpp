#include<bits/stdc++.h>
using namespace std;

#include <queue>
#include <set>
class Solution {
	public:
		int orangesRotting(vector<vector<int>>& grid) {
			auto gridcpy (grid);
			int cols = gridcpy.front().size(), rows = gridcpy.size();
			queue<std::pair<int,int>> rotten_pos;
			int num_of_rotten{}, num_of_oranges{};

			for(int i{}; i < rows; i++){
				for(int j{}; j < cols; j++){
					if(gridcpy[i][j] == 2){
						rotten_pos.push({i, j});
						num_of_rotten++;
						num_of_oranges++;
					}
					if(gridcpy[i][j] == 1) num_of_oranges++;
				}
			}

			int minutes{};
			while(not rotten_pos.empty()){
				int len = rotten_pos.size();
				for(size_t i{}; i < len; i++){
					auto pos { rotten_pos.front() };
					rotten_pos.pop();

					std::set<pair<int,int>> new_rotten {};
					int x = pos.first, y = pos.second;
					if(x-1 >= 0 and gridcpy[x-1][y] == 1){
						new_rotten.insert({x-1, y});
						gridcpy[x-1][y] = 2;
					}
					if(x+1 < rows and gridcpy[x+1][y] == 1){
						new_rotten.insert({x+1, y});
						gridcpy[x+1][y] = 2;
					}
					if(y-1 >= 0 and gridcpy[x][y-1] == 1){
						new_rotten.insert({x, y-1});
						gridcpy[x][y-1] = 2;
					}
					if(y+1 < cols and gridcpy[x][y+1] == 1){
						new_rotten.insert({x, y+1});
						gridcpy[x][y+1] = 2;
					}

					num_of_rotten += new_rotten.size();
					for(auto pr : new_rotten) rotten_pos.push(pr);

				}
					minutes++;
			}

			return num_of_oranges == num_of_rotten ? minutes : -1;
		}
};

int main(){
}


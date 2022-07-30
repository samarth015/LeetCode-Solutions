#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
		for(auto &row : image) std::reverse(row.begin(), row.end());
		for(auto &row : image) for(auto &ele : row) ele = !ele; 
		return image;
    }
};

int main(){
}


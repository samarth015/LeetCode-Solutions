#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> currrow {1}, nextrow{};
		for(size_t i{0}; i < rowIndex; i++){
			nextrow.push_back(1);
			for(size_t j{1}; j < i + 1; j++)
				nextrow.push_back( currrow[j-1] + currrow[j] );
			nextrow.push_back(1);
			currrow = nextrow;
			nextrow.clear();
		}
		return currrow;
    }
};

int main(){
}


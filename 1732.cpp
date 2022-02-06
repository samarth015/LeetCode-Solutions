#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
		int maxalt{0}, alt{0};
		for(auto g : gain){
			alt += g;
			if(maxalt < alt) maxalt = g;
		}
		return maxalt;
    }
};

int main(){
}


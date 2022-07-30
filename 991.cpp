#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int startValue;
		int minopers(int target){
			if(startValue >= target) return startValue - target;
			else if(target % 2) return minopers
		}
public:
    int brokenCalc(int startValue, int target) {
		this->startValue = startValue;
		return minopers(target);
	}
};

//wrong solution
/*
class Solution {
public:
    int brokenCalc(int startValue, int target) {
		int doubs = 0;
		while(startValue < target) startValue *= 2, doubs++;
		return doubs + startValue - target;
};
*/

int main(){
	cout << Solution{}.brokenCalc(5, 8);
}


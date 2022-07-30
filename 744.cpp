#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
		auto it = upper_bound(letters.begin(), letters.end(), target);
		return ( letters.end() == it ? letters[0] : *it );
    }
};

int main(){
}


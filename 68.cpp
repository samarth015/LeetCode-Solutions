#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		string justifyRow(vector<string> &row, int ws){
			int ngaps = row.size() - 1;
			if(ngaps == 0){
				return row.back() + string(ws, ' ');
			}
			else{
				int gap = ws / ngaps, nlongergaps = ws % ngaps;
				string resrow;
				for(int i = 0; i < ngaps; i++){
					resrow += row[i] + string(gap, ' ');
					if(nlongergaps-- > 0) resrow.push_back(' ');
				}
				return resrow + row.back();
			}
		}
	public:
		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			vector<string> res, curr_row;
			int nonws = 0, currWidth = maxWidth;
			for(auto &word : words){
				int wordsize = word.size();
				if(wordsize > currWidth){
					int ws = maxWidth - nonws;
					res.push_back(justifyRow(curr_row, ws));
					curr_row.clear(); 
					currWidth = maxWidth;
					nonws = 0;
				}
				curr_row.push_back(word);
				currWidth -= wordsize + 1;
				nonws += wordsize;
			}
			if(!curr_row.empty()) {
				string resrow;
				for(int i = 0; i < curr_row.size() - 1; i++)
					resrow += curr_row[i] + " ";
				resrow += curr_row.back();
				res.push_back(resrow + string(maxWidth - resrow.size(), ' '));
				
			}
			return res;
		}
};

int main(){
}


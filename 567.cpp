#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool checkInclusion(string s1, string s2) {
			unordered_map<char, int> s1charscount {}, curr_subseq_chars_count{};
			for(char ch : s1) s1charscount[ch]++;
			// for(auto [ch, count] : s1charscount) cout << ch << ' ' << count << endl;
			int curr_subseq_len = 0, first_char_subseq = 0;

			for(int i = 0; i < s2.size(); i++){
				curr_subseq_chars_count[s2[i]]++;
				curr_subseq_len++;

				if(s1charscount.find(s2[i]) == s1charscount.end()){
					curr_subseq_chars_count.clear();
					curr_subseq_len = 0;
				}
				else if(curr_subseq_chars_count[s2[i]] > s1charscount[s1[i]]){
					while(first_char_subseq != s2[i]){
						curr_subseq_chars_count[s2[i]]--;
						first_char_subseq++;
						curr_subseq_len--;
					}
					curr_subseq_chars_count[s2[i]]--;
					first_char_subseq++;
					curr_subseq_len--;
				}
				else if(curr_subseq_len == s1.size()){
					return true;
				}
			}

			return false;
		}
};

int main(){
	cout << Solution{}.checkInclusion("ab", "eidbaooo");
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		
		// reverse the whole string then reverse order of each word. Or reverse the order of each word then whole string.
		string reverseWords(string s){
			string rev_s (s.rbegin(), s.rend()); 
			string rev_word_s = "", currword = "";
			for(int i = 0; i < rev_s.size(); i++){
				if(rev_s[i] != ' '){
					currword.push_back(rev_s[i]);
				}
				else{
					rev_word_s = " " + currword + rev_word_s;
					currword.clear();
				}
			}
			rev_word_s = currword + rev_word_s;
			return rev_word_s;
		}

		//new string
		/*
		   string reverseWords(string s){
		   int i;
		   string newstr = "", currwordrev = "";
		   for(i = 0; i < s.size(); i++){
		   if(s[i] == ' '){
		   newstr += ' ' + currwordrev;
		   currwordrev = "";
		   }
		   else
		   currwordrev = s[i] + currwordrev;
		   }
		   newstr += " " + currwordrev;
		   newstr.erase(0, 1);
		   return newstr;
		   }
		   */

		//inplace
		/*
		   void reverseWords(string s){
		   int i, currword;
		   for(i = 0, currword = 0; i < s.size(); i++){
		   if(s[i] == ' ' or s[i] == ',' or s[i] == '\''){
		   int j = i - 1;
		   while(currword < j) std::swap(s[currword++], s[j--]);
		   currword = i + 1;
		   }
		   }
		   while(currword < i - 1) std::swap(s[currword++], s[i--]);
		   }
		   */
};

int main(){
	cout << Solution{}.reverseWords("This is code to reverse each word.");
}

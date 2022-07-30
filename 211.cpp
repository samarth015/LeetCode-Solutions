#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
	private:
		class trienode{
			public:
			vector<trienode*> characters;
			bool isWordEnd;
			trienode(): characters(26, nullptr), isWordEnd{false} {}
		};

		trienode* root;

		void clear(trienode *root){
			if(root){
				for(trienode *no: root->characters)
					clear(no);
				delete root;
			}
		}

		bool search(string word, trienode* root){
			trienode *curr = root;
			int n = word.size();
			for(int i = 0; i < n; i++){
				char c = word[i];
				if(c != '.'){
					trienode *next = curr->characters[c-'a'];
					if(next == nullptr) return false;
					curr = next;
				}
				else{
					string remaining_word = string(word.begin()+i+1, word.end());
					// U can also use std::any_of for the below lines.
					for(auto no: curr->characters)
						if(no != nullptr and search(remaining_word, no) == true)
							return true;
					return false;
				}
			}
			return curr->isWordEnd;
		}

	public:
		WordDictionary(): root{ new trienode{} } {}

		~WordDictionary(){
			clear(root);
		}

		void addWord(string word) {
			trienode* curr = root;
			for(char c: word){
				trienode* next = curr->characters[c-'a'];
				if(next == nullptr) next = curr->characters[c-'a'] = new trienode();
				curr = next;
			}
            curr->isWordEnd = true;
		}

		bool search(string word) {
			return search(word, this->root);
		}
};


// TLE
class WordDictionary3 {
	private:
		unordered_set<string> dict;
	public:
		void addWord(string word) {
			dict.insert(word);
		}

		bool search(string word) {
			vector<string> possible_words { "" };
			for(char c: word){
				if(c != '.'){
					for(auto &pw: possible_words) pw.push_back(c);
				}
				else{
					vector<string> tmp;
					for(auto &pw: possible_words)
						for(char i = 'a'; i <= 'z'; i++)
							tmp.push_back(pw+i);

					possible_words = move(tmp);
				}
			}

			return any_of(possible_words.begin(), possible_words.end(), 
					[dict=&dict](auto& word){ return dict->find(word) != dict->end(); });
		}
};

int main(){
}


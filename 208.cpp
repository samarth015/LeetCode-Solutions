#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
	class node{
		public:
		array<node*, 26> characters;
		bool isCompleteWord;
		node(): characters(), isCompleteWord{false} {}
	};

	node *root;

	void clear(node* root){
		for(auto no: root->characters)
			if(no) clear(no);
		delete root;
	}
	node* findnode(string str){
		node *curr = root;
		for(auto c: str){
			if(curr == nullptr) break; 
			curr = curr->characters[c - 'a'];
		}
		return curr;
	}

public:
    Trie(): root{new node()} {}
	
	~Trie(){
		clear(root);
	}
    
    void insert(string word) {
		node *curr = root;
		for(char c: word){
			node* next = curr->characters[c - 'a'];
			if(next == nullptr){
				next = curr->characters[c - 'a'] = new node();
			}
			curr = next;
		}
		curr->isCompleteWord = true;
    }
    
    bool search(string word) {
		node *no = findnode(word);
		return no != nullptr and no->isCompleteWord;
    }
    
    bool startsWith(string prefix) {
		return findnode(prefix) != nullptr;
    }
};

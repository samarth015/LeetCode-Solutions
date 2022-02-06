#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<queue>

class Solution {
	    vector<vector<int>> levelOrder(TreeNode* root){
			if(root == nullptr) return {};
			std::queue<TreeNode*> qu {}; qu.push(root);
			vector<vector<int>> lvlord {};
			while(not qu.empty()){
				vector<int> curr_lvl {};
				size_t len {qu.size()};
				for(std::size_t i{}; i < len; i++){
					curr_lvl.push_back(qu.front()->val);
					if(qu.front()->left) qu.push(qu.front()->left);
					if(qu.front()->right) qu.push(qu.front()->right);
					qu.pop();
				}
				lvlord.push_back(std::move(curr_lvl));
			}
			return lvlord;
		}
};

int main(){
}

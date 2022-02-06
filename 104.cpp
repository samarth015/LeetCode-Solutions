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
	public:
		int maxDepth(TreeNode* root){
			if(root == nullptr) return 0;
			int maxd = 0;
			std::queue<TreeNode*> qu {};
			qu.push(root);
			while(not qu.empty()){
				maxd++;
				size_t len { qu.size() };
				for(size_t i{}; i < len; i++){
					if(qu.front()->left) qu.push(qu.front()->left);
					if(qu.front()->right) qu.push(qu.front()->right);
					qu.pop();
				}
			}
			return maxd;
		}

		// One liner
		/*
		int maxDepth(TreeNode* root){
			return ( root ? 1 + std::max( maxDepth(root->left), maxDepth(root->right) ) : 0 );
		}
		*/
};

int main(){
}

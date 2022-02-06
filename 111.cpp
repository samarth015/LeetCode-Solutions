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
	private:
		int minDepthInner(TreeNode* root){
			if(root->left and root->right){
				return 1 + std::min(minDepthInner(root->left), minDepthInner(root->right));	
			}
			else if(root->left){
				return 1 + minDepthInner(root->left);
			}
			else if(root->right){
				return 1 + minDepthInner(root->right);
			}
			else{
				return 1;
			}
		}

	public:
		// One liner
		int minDepth(TreeNode* root){
			if(root) return minDepthInner(root);
			else return 0;
		}

		//queues
		/*
		int minDepth(TreeNode* root){
			if(root == nullptr) return 0;
			int mind = 0;
			std::queue<TreeNode*> qu {};
			qu.push(root);
			while(not qu.empty()){
				mind++;
				size_t len { qu.size() };
				for(size_t i{}; i < len; i++){
					TreeNode* left{qu.front()->left}, *right{qu.front()->right};
					if(not(right or left)) return mind;
					if(qu.front()->left) qu.push(qu.front()->left);
					if(qu.front()->right) qu.push(qu.front()->right);
					qu.pop();
				}
			}
			return mind;
		}
		*/

};

int main(){
}

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

class Solution {
	private:
		vector<int> inord;

		void inorderTraversalInner(TreeNode* root){
			if(root){
				inorderTraversalInner(root->left);
				inord.push_back(root->val);
				inorderTraversalInner(root->right);
			}
		}

	public:
		Solution(): inord{} {}
		vector<int> inorderTraversal(TreeNode* root){
			inorderTraversalInner(root);
			return inord;
		}
};

class Solution3 {
	public:
		vector<int> inorderTraversal(TreeNode* root){
			if(root == nullptr) return {};
			vector<int> res;
			stack<TreeNode*> treestack;
			TreeNode* curr = root;
			while( curr or treestack.size() ){
				while(curr){
					treestack.push(curr);
					curr = curr->left;
				}
				res.push_back(treestack.top()->val);
				curr = treestack.top()->right;
				treestack.pop();
			}
		return res;
		}
};

class Solution2 {
	public:
		vector<int> inorderTraversal(TreeNode* root){
			if(root == nullptr) return {};
			vector<int> res;
			stack<TreeNode*> treestack;
			treestack.push(root);
			int prev_size = 0;
			while( not treestack.empty() ){
				int size = treestack.size();
				if(prev_size <= size and treestack.top()->left){
					treestack.push( treestack.top()->left );
				}
				else{
					TreeNode* top = treestack.top();
					treestack.pop();
					res.push_back( top->val );
					if( top->right ) treestack.push( top->right );
				}
				prev_size = size;
			}
		return res;
		}
};

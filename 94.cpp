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

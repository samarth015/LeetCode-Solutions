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
		int diameter;	
		int find_max_depth(TreeNode* root){
			if(root == nullptr) return 0;
			int left_depth = find_max_depth(root->left);
			int right_depth = find_max_depth(root->right);
			if(left_depth + right_depth > diameter) diameter = left_depth + right_depth;
			return 1 + max(left_depth, right_depth);
		}
	public:
		int diameterOfBinaryTree(TreeNode* root) {
			diameter = 0;
			find_max_depth(root);
			return diameter;
		}
};

int main(){
}


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
		int sum = 0;
		void convertBST_helper(TreeNode* root) {
			if(root == nullptr) return;
			convertBST_helper(root->right);
			sum += root->val;
			root->val = sum;
			convertBST_helper(root->left);
		}
	public:
		TreeNode* convertBST(TreeNode* root) {
			convertBST_helper(root);
			return root;

		}
};

int main(){
}


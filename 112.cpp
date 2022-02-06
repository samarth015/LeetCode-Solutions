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
		int target;

		bool sumPaths(TreeNode* root, int S){
			if(root == nullptr) return false;
			else if(root->left == nullptr and root->right == nullptr) return S + root->val == target;
			else return sumPaths(root->left, S + root->val) or sumPaths(root->right, S + root->val);
		}

	public:
		bool hasPathSum(TreeNode* root, int targetSum) {
			target = targetSum;
			return sumPaths(root, 0);
		}
};

int main(){
}

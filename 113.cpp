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

#include<vector>
class Solution{
	private:
		int target;
		vector<vector<TreeNode*>> paths{}

		void sumPaths(TreeNode* root, int S, vector<TreeNode*> path){
			if(root == nullptr) return;
			else if(root->left == nullptr and root->right == nullptr and S + root->val){
				path.push(root);
				paths.path
			}
			else {
				sumPaths(root->left, S + root->val); 
				sumPaths(root->right, S + root->val);
			}
		}

	public:
		vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
			target = targetSum;
			return sumPaths(root, vector<TreeNode*> {});
		}
};

int main(){
}

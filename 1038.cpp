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
		int helper(TreeNode *root, int larger_sum){
			if(root == nullptr) return 0;
			root->val += helper(root, larger_sum);
			helper(root->left, root->val);
			return root->val;
		}
public:
    TreeNode* bstToGst(TreeNode* root) {
		if(root == nullptr) return nullptr;
		helper(root, 0);
		return root;
    }
};

int main(){
}


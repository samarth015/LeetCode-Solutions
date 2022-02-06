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
		int Sum;

		void sumNumbers(TreeNode* root, int S){
			if(root == nullptr) return;
			else if(root->left == nullptr and root->right == nullptr) Sum += root->val + S*10;
			else{
				sumNumbers(root->left, S*10 + root->val);
				sumNumbers(root->right, S*10 + root->val);
			}
		}

	public:
		Solution(): Sum{0} {}

		int sumNumbers(TreeNode* root){
			sumNumbers(root, 0);
			return Sum;
		}
};

int main(){
}


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

#include <vector>
class Solution2 {
	private:

	public:
		int deepestLeavesSum(TreeNode* root){
			if(!root) return 0;
			vector<TreeNode*> curr_level{}, new_level{root};

			while(not new_level.empty()){
				curr_level = std::move(new_level);
				new_level = vector<TreeNode*>{};

				for(auto node : curr_level){
					if(node->left) new_level.push_back(node->left);
					if(node->right) new_level.push_back(node->right);
				}
			}

			int sum = 0;
			for(auto node : new_level) sum += node->val;
			return sum;
		}
};

//using recursion
class Solution {
	private:
		int sum, deepest_level;
		void deepestLeavesSum(TreeNode* root, int curr_level) {
			if(not root) return;
			if(curr_level > deepest_level){
				deepest_level = curr_level;
				sum = 0;
			}
			if(curr_level == deepest_level and !root->left and !root->right){
				sum += root->val;
			}
			deepestLeavesSum(root->left, curr_level+1);
			deepestLeavesSum(root->right, curr_level+1);
		}

	public:
		Solution(): sum{}, deepest_level{} {};

		int deepestLeavesSum(TreeNode* root) {
			deepestLeavesSum(root, 0);
			return sum;
		}
};

int main(){
}


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


#include<algorithm>
class Solution {
	private:
		bool nodes_are_mirror(TreeNode* left, TreeNode* right){
			return (left == nullptr and right == nullptr)
					or
				   (left != nullptr and right != nullptr and left->val == right->val);
		}

	public:
		bool isSymmetric(TreeNode* root){
			if(root == nullptr or (root->left == nullptr and root->right == nullptr)) return true;

			std::vector<TreeNode*> left_currlvl{}, right_currlvl{}, left_prevlvl{root->left}, right_prevlvl{root->right};
			while(not(left_prevlvl.empty() or right_prevlvl.empty())){
				for(auto no : left_prevlvl){
					if(no){
						left_currlvl.push_back(no->left);
						left_currlvl.push_back(no->right);
					}
				}
				for(auto no : left_prevlvl){
					if(no){
						right_currlvl.push_back(no->left);
						right_currlvl.push_back(no->right);
					}
				}

				if(left_currlvl.size() != right_currlvl.size()) return false;
				size_t len = left_currlvl.size();
				for(size_t i{}; i < len; i++){
					if(not nodes_are_mirror(left_currlvl[i], right_currlvl[len - 1 - i])) return false;
				}

				auto it = std::remove(left_currlvl.begin(), left_currlvl.end(), nullptr);
				left_currlvl.erase(it, left_currlvl.end());

				it = std::remove(right_currlvl.begin(), right_currlvl.end(), nullptr);
				right_currlvl.erase(it, right_currlvl.end());

				left_prevlvl = std::move(left_currlvl);
				right_prevlvl = std::move(right_currlvl);

				left_currlvl.clear();
				right_currlvl.clear();
			}
			return left_prevlvl.empty() and right_prevlvl.empty();
		}
};

int main(){
}

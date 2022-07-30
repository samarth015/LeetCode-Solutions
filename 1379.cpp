#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
	private:
	TreeNode* target;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned) {
		if(original == target) return cloned;
		else if(original == nullptr) return nullptr;
		else {
			TreeNode* left_search, *right_search;
			left_search = getTargetCopy(original->left, cloned->left);
			right_search = getTargetCopy(original->right, cloned->right);
			if(left_search) return left_search;
			return right_search;
		}
	}
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		this->target = target;
		return getTargetCopy(original, cloned);
    }
};

int main(){
}


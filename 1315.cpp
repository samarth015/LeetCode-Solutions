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
public:
    int sumEvenGrandparent(TreeNode* root) {
		if(root == nullptr) return 0;
		int sum = 0;
		if(root->val % 2 == 0){
			TreeNode *left{root->left}, *right{root->right};
			if(left) sum += ( left->left ? left->left->val : 0 ) + ( left->right ? left->right->val : 0 );
			if(right) sum += ( right->right ? right->right->val : 0 ) + ( right->left ? right->left->val : 0);
		}
		return sum + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
    }
};

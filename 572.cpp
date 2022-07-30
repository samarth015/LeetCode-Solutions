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
bool treeIsEqual(TreeNode *r1, TreeNode *r2){
	if(r1 == nullptr or r2 == nullptr) return r1 == r2;
	return r1->val == r2->val and treeIsEqual(r1->left, r2->left) and treeIsEqual(r1->right, r2->right);
}
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int n = q.size();
			for(int i = 0; i < n; i++){
				TreeNode* no = q.front();
				q.pop();
				if(treeIsEqual(subRoot, no)) return true;
				if(no->left) q.push(no->left);
				if(no->right) q.push(no->right);
			}
		}
		return false;
    }
};

int main(){
}


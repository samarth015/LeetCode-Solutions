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

// BFS
class Solution {
	public:
		vector<vector<int>> levelOrderBottom(TreeNode* root) {
			if(root == nullptr) return {};
			queue<TreeNode*> q;
			q.push(root);
			vector<vector<int>> res;
			while(not q.empty()){
				int n = q.size();
				res.push_back({});
				for(int i = 0; i < n; i++){
					TreeNode* no = q.front();
					if(no->left) q.push(no->left);
					if(no->right) q.push(no->right);
					res.back().push_back(no->val);
					q.pop();
				}
			}
			reverse(res.begin(), res.end());
			return res;
		}
};

//DFS
class Solution2 {
	private:
		vector<vector<int>> collector;
		void collect(TreeNode *root, int depth){
			if(root == nullptr) return;
			if(depth == collector.size()) collector.push_back({});
			collector[depth].push_back(root->val);
			collect(root->left, depth + 1);
			collect(root->right, depth + 1);
		}

	public:
		vector<vector<int>> levelOrderBottom(TreeNode* root) {
			collector = vector<vector<int>>{};
			collect(root, 0);
			return vector<vector<int>> (collector.rbegin(), collector.rend());
		}
};




int main(){
}


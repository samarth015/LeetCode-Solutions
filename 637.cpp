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

// DFS
class Solution {
private:
	vector<pair<double, int>> info;
	void collect_info(TreeNode *root, int depth){
		if(root == nullptr) return;
		if(depth >= info.size()) info.push_back({0,0});
		info[depth].first += root->val;
		info[depth].second++;
		collect_info(root->left, depth+1);
		collect_info(root->right, depth+1);
	}
public:
    vector<double> averageOfLevels(TreeNode* root) {
		if(root == nullptr) return {};
		collect_info(root, 0);
		vector<double> res;
		for(auto pr : info) res.push_back(pr.first / pr.second);
		return res; 
    }
};

// BFS
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
		if(root == nullptr) return {};
		vector<double> res;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int level_size = q.size();
			double sum = 0;
			for(int i = 0; i < level_size; i++){
				TreeNode* no = q.front();
				q.pop();
				sum += no->val;
				if(no->left) q.push(no->left);
				if(no->right) q.push(no->right);
			}
			res.push_back(sum / level_size);
		}
		return res;
    }
};

int main(){
}


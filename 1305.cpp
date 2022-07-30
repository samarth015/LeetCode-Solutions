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
	vector<int> collector;
	void getElements(TreeNode* root){
		if(not root) return;
		getElements(root->left);
		collector.push_back(root->val);
		getElements(root->right);
	}

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		getElements(root1);
		vector<int> flattree1 { move(collector) };
		collector = vector<int>{};
		getElements(root2);
		vector<int> flattree2 { move(collector) };
		vector<int> result( flattree2.size() + flattree1.size() );
		std::merge(flattree1.begin(), flattree1.end(), flattree2.begin(), flattree2.end(), result.begin()); 
		return result;
    }
};

int main(){
}


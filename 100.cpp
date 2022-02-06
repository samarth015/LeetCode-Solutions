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

#include <queue>
class Solution {
	private:
		bool nodes_are_equivalent(TreeNode *p, TreeNode *q){
			if(!p or !q) return p == q;
			else return p->val == q->val;
		}
	public:
		bool isSameTree(TreeNode* p, TreeNode* q) {
			queue<TreeNode*> q1{}, q2{};
			q1.push(p); q2.push(q);
			while(not q1.empty()){
				size_t len{q1.size()};
				for(int i = 0; i < len; i++){
					TreeNode *no1{q1.front()}, *no2{q2.front()};
					if(not nodes_are_equivalent(no1, no2)) return false;
					if(no1){
						q1.push(no1->left); q1.push(no1->right);
						q2.push(no2->left); q2.push(no2->right);
					}
					q1.pop(); q2.pop();
				}
			}

			return true;
		}
};

class Solution2 {
	public:
		bool isSameTree(TreeNode* p, TreeNode* q) {
			if(!p or !q)
				return p == q;
			else
				return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
		}
};

int main(){
}


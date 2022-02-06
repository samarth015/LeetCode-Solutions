// quick/merge sort will probably work for linked lists. It take N time to find the mid and there are logN mid findings steps
// so --> NlogN
// NlogN time to divide and NlogN to merge
//
// is sorted until. skip sorted elements

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	private: 
		std::pair<ListNode*, ListNode*> partition(ListNode* head, ListNode* end){
			ListNode *fast{head->next}, *slow{head};
			int pivot_val = head->val;
			while(fast != end){
				if(fast->val < pivot_val){
					std::swap(fast->val, slow->val);
					slow = slow->next;
				}
				fast = fast->next;
			}

			ListNode *pivot_node = slow;
			while(slow->val != pivot_val) slow = slow->next;
			slow->val = pivot_node->val;
			pivot_node->val = pivot_val;

			return {pivot_node, pivot_node->next};
		}

		void sortList(ListNode* head, ListNode* end){
			if(head == end) return;
			auto parts { partition(head, end) };
			auto left_end {parts.first}, right_beg{parts.second};
			sortList(head, left_end);
			sortList(right_beg, end);
		}

	public:
		ListNode* sortList(ListNode* head){
			sortList(head, nullptr);
			return head;
		}
};

//selection sort
class Solution2 {
	public:
		ListNode* sortList(ListNode* head){
			for(ListNode *slow{head}; slow; slow = slow->next){
				ListNode* min_node = slow;
				for(ListNode *fast{slow->next}; fast; fast = fast->next){
					if(fast->val < min_node->val) min_node = fast;
				}
				std::swap(min_node->val, slow->val);
			}
			return head;
		}
};

int main(){
	ListNode *zero { new ListNode{0, nullptr } };
	ListNode *four { new ListNode{-1, zero } };
	ListNode *three { new ListNode{-1, four } };
	ListNode *five { new ListNode{-1, three } };
	ListNode *mone { new ListNode{-1, five } };
	ListNode *head { new ListNode{-1, mone } };
	while(head){
		cout << head->val << ' ';
		head = head->next;
	}
}

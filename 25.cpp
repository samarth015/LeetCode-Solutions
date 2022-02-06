
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
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			if(k == 1 or head == nullptr or head->next == nullptr) return head;
			ListNode dummy {0, head};

			int len = 0, ngroups;
			ListNode *tmp {head};
			while(tmp) len++, tmp = tmp->next;
			ngroups = len / k;

			ListNode *curr{head}, *prev, *next{head->next}, *prev_tail{&dummy}, *prev_head;

			for(int i = 0; i < ngroups; i++){
				prev = nullptr;
				prev_head = curr;
				for(int j = 1; j < k; j++){
					curr->next = prev;
					prev = curr;
					curr = next;
					next = next->next;
				}
				curr->next = prev;
				prev = curr;
				curr = next;
				if(next) next = next->next;

				prev_tail->next = prev;
				prev_tail = prev_head;
			}
            prev_tail->next = curr;
			return dummy.next;
		}
};

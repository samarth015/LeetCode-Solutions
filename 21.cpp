
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
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
			if(not(l1 or l2)) return nullptr;

			ListNode dummy{}, *tail;
			tail = &dummy;
			ListNode **smaller_node;

			while(l1 and l2){
				smaller_node = ( l1->val < l2->val ? &l1 : &l2 );
				tail = tail->next = (*smaller_node);
				*smaller_node = (*smaller_node)->next;
			}

			tail->next = ( l1 ? l1 : l2 );
			return dummy.next;
		}

		// to create a new list
		/*
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
			if(not(l1 or l2)) return nullptr;

			ListNode dummy{}, *tail;
			tail = &dummy;
			ListNode **smaller_node, *remaining;

			while(l1 and l2){
				smaller_node = ( l1->val < l2->val ? &l1 : &l2 );
				tail = tail->next = new ListNode{ (*smaller_node)->val };
				(*smaller_node) = (*smaller_node)->next;
			}

			remaining = ( l1 ? l1 : l2 );
			while(remaining){
				tail = tail->next = new ListNode{ remaining->val };
				remaining = remaining->next;
			}

			return dummy.next;
		}
		*/
};

int main(){
}

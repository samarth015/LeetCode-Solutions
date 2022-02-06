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
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode *ahead{head}, *behind{head};
			for(int i = 0; i < n; i++) ahead = ahead->next;
			if(ahead == nullptr){
				ListNode *new_head {head->next};
				delete head;
				return new_head;
			}

			while(ahead->next) ahead = ahead->next, behind = behind->next;

			ListNode *to_be_deleted = behind->next;
			behind->next = behind->next->next;
			delete to_be_deleted;

			return head;
		}
};

int main(){
}

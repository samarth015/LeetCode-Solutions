
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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

			ListNode dummy{};
			ListNode* curr { &dummy };
			int digit_sum{}, carry{};

			while(l1 and l2){
				digit_sum = carry + l1->val + l2->val;
				carry = digit_sum >= 10;
				curr = curr->next = new ListNode{ digit_sum % 10 };
				l1 = l1->next;
				l2 = l2->next;
			}

			ListNode* remaining { l1 ? l1 : l2 };

			if(carry == 1){
				while(remaining and remaining->val == 9){
					curr = curr->next = new ListNode{};
				}

				if(remaining){
					curr = curr->next = new ListNode{remaining->val + 1};
					remaining = remaining->next;
				}
				else{
					curr = curr->next = new ListNode{1};
				}
			}

			while(remaining){
				curr = curr->next = new ListNode{ remaining->val };
				remaining = remaining->next;
			}

			return dummy.next;
		}
};

int main(){
}


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		bool isPalindrome(ListNode* head) {
			ListNode *fast, *slow;
			fast = slow = head;
			while(fast and fast->next){
				fast = fast->next->next;
				slow = slow->next;
			}
			if(fast) slow = slow->next;
			ListNode *curr{nullptr}, *curr2{head};
			while(slow){
				curr = new ListNode{slow->val, curr};
				slow = slow->next;
			}
			while(curr){
				if(curr->val != curr2->val) return false;
				curr = curr->next;
				curr2 = curr2->next;
			}
			return true;
		}
};

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Much more elegant. I only needed one pointer.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if(head == nullptr or head->next == nullptr) return head;
		ListNode *curr = head;
		while(curr->next){
			if(curr->val == curr->next->val){
				ListNode* tmp = curr->next;
				curr->next = curr->next->next;
				delete tmp;
			}
			else
				curr = curr->next;
		}
		return head;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if(head == nullptr) return nullptr;
		ListNode* fast = head->next, *slow = head;
		while(fast){
			if(fast->val != slow->val){
				slow->next = fast;
				slow = fast;
				fast = fast->next;
			}
			else{
				ListNode *tmp = fast;
				fast = fast->next;
				delete tmp;
			}
		}
		slow->next = nullptr;
		return head;
    }
};

int main(){
}


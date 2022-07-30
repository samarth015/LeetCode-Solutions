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
    ListNode* removeElements(ListNode* head, int val) {
		if(head == nullptr) return nullptr;
		while(head and head->val == val){
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
		}
		ListNode* prev{nullptr}, *curr{head};
		while(curr){
			if(curr->val == val){
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
			}
			else{
				prev = curr;
				curr = curr->next;
			}
		}
		return head;
    }
};

int main(){
}


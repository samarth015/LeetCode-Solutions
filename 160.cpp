
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
		if(headA == nullptr || headB == nullptr) return nullptr;
		ListNode* a{headA}, *b{headB};
		while(a != b){
			if(a) a = a->next; else a = headB;
			if(b) b = b->next; else b = headA;
		}
		return a;
	}
};

// O(4n) time and O(1) space complexity.
/*
class Solution {
	private:
		int ListSize(ListNode *head){
			int Size{0};
			while(head){
				head = head->next;
				Size++;
			}
			return Size;
		}

	public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
		int lenA{ ListSize(headA) }, lenB{ ListSize(headB) };

		ListNode *larger, *smaller;
		if(lenA > lenB){
			larger = headA;
			smaller = headB;
		}
		else{
			larger = headB;
			smaller = headA;
		}

		int lead = abs(lenA - lenB);
		while(lead--) larger = larger->next;

		while(larger){
			if(larger == smaller) return larger;
			larger = larger->next;
			smaller = smaller->next;
		}
		return nullptr;
	}
};
*/

// Hash table. Linear time but bad space complexity.
/*
#include <unordered_set>
class Solution {
	public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
		std::unordered_set<ListNode*> unst {};
		ListNode *curr {headA};
		while(curr){
			unst.insert(curr);
			curr = curr->next;
		}
		curr = headB;
		while(curr){
			if(unst.find(curr) != unst.end()) return curr;
		}
		return nullptr;
	}
};
*/

int main(){
}

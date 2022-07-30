#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Best One
// space O(1) 
// time O(n)
class Solution3 {
public:
    Node* copyRandomList(Node* head) {
		if(head == nullptr) return nullptr;

		Node *curr = head;
		while(curr){
			Node *copy = new Node{curr->val};
			copy->next = curr->next;
			curr->next = copy;
			curr = copy->next;
		}

		curr = head;
		while(curr){
			curr->next->random = (curr->random ? curr->random->next : nullptr);
			curr = curr->next->next;
		}

		Node *newhead = head->next;
		curr = head;
		while(curr){
			Node *copy = curr->next;
			curr->next = copy->next;
			curr = copy->next;
			copy->next = (copy->next ? copy->next->next : nullptr );
		}

		return newhead;
    }
};

// space O(n)
// time O(n)
class Solution {
	unordered_map<Node*,Node*> clone;
public:
    Node* copyRandomList(Node* head) {
		if(head == nullptr) return nullptr;

		Node *curr = head;
		while(curr){
			clone[curr] = new Node{curr->val};
			curr = curr->next;
		}

		curr = head;
		while(curr){
			auto &curr_copy = clone[curr];
			curr_copy->random = clone[curr->random]; 
			curr_copy->next = clone[curr->next]; 
			curr = curr->next;
		}

		return clone[head];
    }
};

// space O(1)
// time O(n^2)
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
		if(head == nullptr) return nullptr;

		Node dummy {0};
		Node *curr = head, *copy_ptr = &dummy;
		while(curr){
			copy_ptr = copy_ptr->next = new Node{curr->val};
			copy_ptr->random = curr->random;
			curr = curr->next;
		}

		Node *copy_curr = dummy.next;
		while(copy_curr){
			if(copy_curr->random != nullptr){
				curr = head, copy_ptr = dummy.next;
				while(curr != copy_curr->random)
					curr = curr->next, copy_ptr = copy_ptr->next;
				copy_curr->random = copy_ptr;
			}
			copy_curr = copy_curr->next;
		}
		return dummy.next;
	}
};

int main(){
}


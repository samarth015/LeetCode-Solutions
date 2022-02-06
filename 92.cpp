struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Single wipe until right th node
class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int left, int right) {
			ListNode dummy {0, head};
			ListNode *curr = &dummy;

			for(int i = 0; i < left - 1; i++) curr = curr->next;
			ListNode *start { curr };

			ListNode *next, *prev{nullptr};
			curr = start->next;
			for(int i = left; i < right + 1; i++){
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}

			start->next->next = curr;
			start->next = prev;

			return dummy.next;
		}
};

// Two wipes through list and a wipe through [left, right]
class Solution2 {
	public:
		ListNode* reverseBetween(ListNode* head,int left, int right) {
			if(left == right) return head;

			ListNode *curr {head}, *start, *end;
			int i = 1;
			for(; i < left - 1; i++) curr = curr->next;
			start = curr;
			for(; i < right + 1; i++) curr = curr->next;
			end = curr;

			ListNode *next, *prev{end};
			curr = (left == 1 ? start : start->next);
			while(curr != end){
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}

			if(left == 1){
				return prev;
			}
			else{
				start->next = prev;
				return head;
			}

		}
};

int main(){
}

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
    ListNode* mergeKLists(vector<ListNode*>& lists){
		ListNode** min_list;
		ListNode dummy_head {};
		ListNode* merged { &dummy_head };
		while(true){
			bool elements_left = false;
			for(auto &li : lists){
				if(li){
					elements_left = true; 
					min_list = &li;
					break;
				}
			}
			if(elements_left == false) break;
			for(auto &li : lists)
				if(li and (*min_list)->val > li->val)
					min_list = &li;
			
			merged = merged->next = new ListNode{ (*min_list)->val };
			*min_list = (*min_list)->next;
		}
		return dummy_head.next;
    }
};

int main(){
}


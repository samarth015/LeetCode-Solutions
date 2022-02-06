#include<bits/stdc++.h>
using namespace std;

class MinStack {
	private:
		struct node{
			int val;
			node *next;
			node(int val, node *next): val{val}, next{next} {};
		};

	node *nums, *mins;

	public:
		MinStack(): nums{nullptr}, mins{nullptr} {}

		~MinStack(){
			node *tmp;
			while(nums){
				tmp = nums;
				nums = nums->next;
				delete tmp;
			}
			while(mins){
				tmp = mins;
				mins = mins->next;
				delete tmp;
			}
		}

		void push(int val){
			nums = new node{val, nums};
			if(mins == nullptr or mins->val >= val) mins = new node{val, mins};
		}

		void pop(){
			if(mins->val == nums->val){
				node *tmp = mins;
				mins = mins->next;
				delete tmp;
			}
			node *tmp = nums;
			nums = nums->next;
			delete tmp;
		}

		int top() const {
			return nums->val;
		}

		int getMin() const {
			return mins->val;
		}
};

//two stacks
/*
#include<stack>
class MinStack {
std::stack<int> nums, mins;
public:
MinStack(): nums{}, mins{} {}

void push(int val){
nums.push(val);
if(mins.empty() or mins.top() >= val) mins.push(val);
}

void pop(){
if(mins.top() == nums.top()) mins.pop();
nums.pop();
}

int top() const {
return nums.top();
}

int getMin() const {
return mins.top();
}
};
*/

// suboptimal but works
/*
   class MinStack {
   private:
   constexpr static size_t MAX_SIZE { 30000 };
   int arr[MAX_SIZE];
   size_t min_index, Size;

   void set_min(){
   min_index = 0;
   for(size_t i{1}; i < Size; i++)
   if(arr[i] < arr[min_index]) min_index = i;
   }

   public:
   MinStack(): arr{}, Size{0}, min_index{0} {}

   bool empty() const {
   return Size == 0;
   }

   void push(int val){
   if(Size < MAX_SIZE){
   arr[Size] = val;
   if(val < arr[min_index]) min_index = Size;
   Size++;
   }
   }

   void pop(){
   if(not empty()){
   Size--;
   if(Size == min_index) set_min();
   }
   }

   int top() const{
   return arr[Size - 1];
   }

   int getMin(){
   return arr[min_index];
   }

   size_t size() const{
   return Size;
   }
   };
   */

int main(){
	MinStack st {};
	st.push(-2);
	st.push(100);
	st.push(-3);
	st.push(-10);
	cout << st.top() << endl;
	cout << st.getMin() << endl;
}

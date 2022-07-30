#include<bits/stdc++.h>
using namespace std;


// Best approach is using two stacks. It takes the same space as one stack and is also remarkably simple.

// Using one stack
// Insert the previous min element below the current min element.
class MinStack4 {
	private:
		stack<int> info;
		int min_val;
	public:
		MinStack4(): info{} {
			min_val = INT_MAX;
		}

		void push(int val) {
			if(val <= min_val){
				info.push(min_val);
				min_val = val;
			}
			info.push(val);
		}

		void pop() {
			if(info.top() == min_val){
				info.pop();
				min_val = info.top();
			}
			info.pop();
		}

		int top() {
			return info.top();
		}

		int getMin() {
			return min_val;
		}
};


// two stacks but stack implemented from scratch as singly linked lists.
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
#include<stack>
class MinStack2 {

	std::stack<int> nums, mins;

	public:
	MinStack2(): nums{}, mins{} {}

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

// suboptimal but works
class MinStack3 {
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
		MinStack3(): arr{}, Size{0}, min_index{0} {}

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

int main(){
	MinStack st {};
	st.push(-2);
	st.push(100);
	st.push(-3);
	st.push(-10);
	cout << st.top() << endl;
	cout << st.getMin() << endl;
}

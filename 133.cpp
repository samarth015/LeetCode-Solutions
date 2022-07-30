#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// dfs
class Solution {
	unordered_map<Node*, Node*> clone;
	
    Node* cloneGraphHelper(Node* node) {
		auto it = clone.find(node);
		if(it != clone.end()) return it->second;

		Node *copy = new Node{node->val};
		clone[node] = copy;

		for(Node* neighbor: node->neighbors){
			Node* neighbor_copy = cloneGraphHelper(neighbor); 
			copy->neighbors.push_back(neighbor_copy);
		}
		return copy;
    }

public:
    Node* cloneGraph(Node* node) {
		if(node == nullptr) return nullptr;
		return cloneGraphHelper(node);
	}
};

// bfs
class Solution2 {
	unordered_map<Node*, Node*> clone;

	public:
	Node* cloneGraph(Node* node) {
		if(node == nullptr) return nullptr;
		Node *copy = new Node{node->val};
		clone[node] = copy;

		queue<Node*> q;
		q.push(node);
		while(not q.empty()){
			int n = q.size();
			while(n--){
				Node *no = q.front();
				q.pop();
				for(Node *neighbor: no->neighbors){
					auto it = clone.find(neighbor);

					if(it == clone.end()){
						Node *neighbor_copy = new Node{neighbor->val};
						it = clone.insert(make_pair(neighbor, neighbor_copy)).first;
						q.push(neighbor);
					}

					// it->second is neighbor copy.
					clone[no]->neighbors.push_back(it->second);
				}
			}
		}
		return copy;
	}
};


int main(){
}


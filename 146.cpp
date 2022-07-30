
#include<list>
#include<unordered_map>
#include<algorithm>
#include <iostream>
using namespace std;

class LRUCache {
	private:
		int cap;
		std::unordered_map<int,pair<int, list<int>::iterator>> data;
		std::list<int> keys;

	public:
		LRUCache(int capacity): cap{ capacity }, data{}, keys{} {}

		int get(int key) {
			auto it = data.find(key);
			if(it == data.end()) return -1;
			keys.erase(it->second.second);
			keys.push_back(key);
			it->second.second = --keys.end();
			return it->second.first;
		}

		void put(int key, int value) {
			auto it = data.find(key);
			if(it != data.end()) keys.erase(it->second.second);

			keys.push_back(key);
			data[key] = make_pair(value, --keys.end());

			if(data.size() > cap){
				data.erase(keys.front());
				keys.pop_front();
			}
		}
};


/*
// slow solution
class LRUCache2 {
private:
int cap;
std::unordered_map<int,int> data;
std::list<int> keys;

public:
LRUCache(int capacity): cap{ capacity }, data{}, keys{} {}

int get(int key) {
auto it = data.find(key);
if(it != data.end()){
keys.erase(std::find(keys.begin(), keys.end(), key));
keys.push_back(key);
return it->second;
}
else{
return -1;
}
}

void put(int key, int value) {
if(data.find(key) != data.end()) keys.erase(std::find(keys.begin(), keys.end(), key));

keys.push_back(key);
data[key] = value;

if(data.size() > cap){
int oldest_key = keys.front();
keys.pop_front();
data.erase(oldest_key);
}
}
};
*/

int main(){
	LRUCache *ob = new LRUCache{2};
	ob->put(2, 1);
	ob->put(1, 1);
	cout << ob->get(2) << endl;
	ob->put(4, 1);
	cout << ob->get(1) << endl;
	cout << ob->get(2) << endl;
	cout << ob->get(4) << endl;
	ob->put(10, 5);
	ob->put(4, 2);
	cout << ob->get(4) << endl;
	cout << ob->get(5) << endl;
	cout << ob->get(10) << endl;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

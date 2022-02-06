
#include<list>
#include<unordered_map>
#include<algorithm>
using namespace std;

class LRUCache {
	private:
		int cap;
		std::unordered_map<int,int> data;
		std::list<int> keys;

	public:
		LRUCache(int capacity): cap{ capacity }, data{}, keys{} {}

		int get(int key) {
			auto kvalit = data.find(key);
			if(kvalit != data.end()){
				keys.erase(std::find(keys.begin(), keys.end(), key));
				keys.push_back(key);
				return kvalit->second;
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

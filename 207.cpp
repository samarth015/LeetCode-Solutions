#include<bits/stdc++.h>
using namespace std;

class Solution3 {
	unordered_set<int> visited;
	unordered_map<int, vector<int>> uv;

	bool isCyclic(int course){
		if(visited.find(course) != visited.end())
			return true;
		auto it = uv.find(course);
		if(it != uv.end()){
			visited.insert(course);
			for(int dependant_course: it->second){
				if(isCyclic(dependant_course))
					return true;
			}
			visited.erase(course);
			uv.erase(course);
		}
		return false;
	}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if(prerequisites.empty()) return true;

		unordered_set<int> independent;
		for(auto &pr: prerequisites){
			if(pr[1] == pr[0]) return false;
			uv[pr[1]].push_back(pr[0]);
			independent.insert(pr[1]);
		}
		for(auto &pr: prerequisites){
			if(independent.find(pr[0]) != independent.end())
				independent.erase(pr[0]);
		}

		if(independent.empty()) return false;

		for(int ind: independent){
			if(isCyclic(ind)) 
				return false;
		}

		return uv.empty();

    }
};

// linkedlist
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_set<int> independent;
		list<vector<int>> prereqlist (prerequisites.begin(), prerequisites.end());
		while(not prereqlist.empty()){
			for(auto &course_pair: prereqlist)
				independent.insert(course_pair[1]);

			for(auto &course_pair: prereqlist){
				if(independent.find(course_pair[0]) != independent.end())
					independent.erase(course_pair[0]);
			}

			if(independent.empty()) return false;

			auto it = prereqlist.begin();
			while(it != prereqlist.end()){
				int course = (*it)[1];
				if(independent.find(course) != independent.end())
					it = prereqlist.erase(it);
				else
					it++;
			}

			independent.clear();
		}
		return true;
    }
};

// vector

class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_set<int> independent;
		while(not prerequisites.empty()){
			for(auto &course_pair: prerequisites)
				independent.insert(course_pair[1]);

			for(auto &course_pair: prerequisites){
				if(independent.find(course_pair[0]) != independent.end())
					independent.erase(course_pair[0]);
			}

			if(independent.empty()) return false;

			auto newend = remove_if(prerequisites.begin(), prerequisites.end(),
					[&independent](auto &pr){ return independent.find(pr[1]) != independent.end(); });

			prerequisites.erase(newend, prerequisites.end());

			independent.clear();
		}
		return true;
    }
};


int main(){
}


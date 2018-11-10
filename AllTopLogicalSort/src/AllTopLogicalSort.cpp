#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
vector<int> indegrees;

void all(vector<int> answer, vector<bool> visited){
	if(answer.size() == graph.size()){
		for(int i : answer){
			cout << i << " ";
		}
		cout << endl;

		return;
	}

	for(int i = 0; i < (int) graph.size(); i++){
		if(indegrees[i] == 0 && !visited[i]){
			for(auto j : graph[i]){
				indegrees[j]--;
			}

			answer.push_back(i);
			visited[i] = true;
			all(answer, visited);
			visited[i] = false;
			answer.pop_back();

			for(auto j : graph[i]){
				indegrees[j]++;
			}
		}
	}
}

int main() {
	vector<int> zero = {};
	vector<int> one = {};
	vector<int> two = {3};
	vector<int> three = {1};
	vector<int> four = {0, 1};
	vector<int> five = {0, 2};

	graph.insert(make_pair(0, zero));
	graph.insert(make_pair(1, one));
	graph.insert(make_pair(2, two));
	graph.insert(make_pair(3, three));
	graph.insert(make_pair(4, four));
	graph.insert(make_pair(5, five));

	indegrees.push_back(2);
	indegrees.push_back(2);
	indegrees.push_back(1);
	indegrees.push_back(1);
	indegrees.push_back(0);
	indegrees.push_back(0);

	vector<int> answer;
	vector<bool> visited (6, false);

	all(answer, visited);

	return 0;
}

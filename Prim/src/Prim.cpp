#include <bits/stdc++.h>

using namespace std;
vector<bool> visited;
map<int, vector<pair<int, int>>> graph;
int MST_cost = 0;

void process(int u, priority_queue<pair<int, int>>& pq){
	visited[u] = true;

	for(pair<int, int> n : graph[u]){
		if(!visited[n.first]){
			pq.push(make_pair(n.second * -1, n.first));
		}
	}
}

void Prim(int i){
	priority_queue<pair<int, int>> pq;
	process(i, pq);

	while(!pq.empty()){
		pair<int, int> u = pq.top();
		pq.pop();
//		cout << u.first << " " << u.second << endl;

		if(!visited[u.second]){
			MST_cost += (u.first * -1);
		}

		process(u.second, pq);
	}
}

int main() {
	visited.assign(4, false);
	vector<pair<int, int>> zero = {{3, 100}, {1, 2}};
	vector<pair<int, int>> one = {{3, 2}, {2, 100}};
	vector<pair<int, int>> two = {};
	vector<pair<int, int>> three = {{2, 1}};

	graph.insert(make_pair(0, zero));
	graph.insert(make_pair(1, one));
	graph.insert(make_pair(2, two));
	graph.insert(make_pair(3, three));

	for(auto i : graph){
		if(!visited[i.first]){
			Prim(i.first);
		}
	}

	cout << MST_cost << endl;

	return 0;
}

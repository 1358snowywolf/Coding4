#include <bits/stdc++.h>

using namespace std;
map<int, vector<pair<int, int>>> neighbors;

void process(int v, priority_queue<pair<int, int>>& pq, vector<bool>& visited){
	visited[v] = true;

	for(auto u : neighbors[v]){
		if(visited[u.first]) continue;
		pq.push({u.second * -1, u.first});
	}
}

int Prim(){
	priority_queue<pair<int, int>> pq;
	vector<bool> visited (neighbors.size(), false);
	process(0, pq, visited);
	int cost = 0;

	while(!pq.empty()){
		auto u = pq.top();
		pq.pop();

//		cout << u.first * -1 << " " << u.second << endl;

		if(visited[u.second]) continue;

		cost += (u.first * -1);
		process(u.second, pq, visited);
	}

	return cost;
}

int main() {
	int N, M;

	while(true){
		cin >> M >> N;
		neighbors.clear();
		if(N == 0 && M == 0) break;
		int totalWeights = 0;

		for(int i = 0; i < N; i++){
			int u, v, w;
			cin >> u >> v >> w;

			totalWeights += w;
			neighbors[u].push_back({v, w});
			neighbors[v].push_back({u, w});
		}

		int cost = Prim();
		cout << totalWeights - cost << endl;
	}

	return 0;
}

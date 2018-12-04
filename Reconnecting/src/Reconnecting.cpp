#include <bits/stdc++.h>

using namespace std;

void process(priority_queue<pair<int, int>>& pq, vector<bool>& visited, map<int, vector<pair<int, int>>> neighbors, int v){
	visited[v] = true;

	for(auto n : neighbors[v]){
		if(!visited[n.first]){
			pq.push(make_pair(-1 * n.second, n.first));
		}
	}
}

int Prim(map<int, vector<pair<int, int>>> neighbors){
	vector<bool> visited (neighbors.size(), false);
	priority_queue<pair<int, int>> pq;
	process(pq, visited, neighbors, 0);
	int cost = 0;

	while(!pq.empty()){
		auto u = pq.top(); pq.pop();

		if(!visited[u.second]){
			cost += (-1 * u.first);
			process(pq, visited, neighbors, u.second);
		}
	}

	return cost;
}

int main() {
	int N;

	while(cin >> N){
		for(int i = 0; i < N - 1; i++){
			int a, b, c;
			cin >> a >> b >> c;
		}

		int K;
		cin >> K;
		map<int, vector<pair<int, int>>> neighbors;
		map<int, vector<pair<int, int>>> newNeighbors;

		for(int i = 0; i < K; i++){
			int u, v, w;
			cin >> u >> v >> w;
			newNeighbors[u - 1].push_back(make_pair(v - 1, w));
			newNeighbors[v - 1].push_back(make_pair(u - 1, w));
		}

		int M;
		cin >> M;

		for(int i = 0; i < M; i++){
			int u, v, w;
			cin >> u >> v >> w;
			newNeighbors[u - 1].push_back(make_pair(v - 1, w));
			newNeighbors[v - 1].push_back(make_pair(u - 1, w));
			neighbors[u - 1].push_back(make_pair(v - 1, w));
			neighbors[v - 1].push_back(make_pair(u - 1, w));
		}

		int old = Prim(neighbors);
		int improved = Prim(newNeighbors);

		cout << old << endl << improved << endl << endl;
	}

	return 0;
}

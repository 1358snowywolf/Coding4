#include <bits/stdc++.h>

using namespace std;

void process(string v, set<string>& visited, priority_queue<pair<int, string>>& pq, map<string,vector<pair<string, int>>> graph){
	visited.insert(v);

	for(auto u : graph[v]){
		if(visited.find(u.first) == visited.end()){
			pq.push(make_pair(u.second * -1, u.first));
		}
	}
}

int Prim(map<string, vector<pair<string, int>>> network, string start){
	priority_queue<pair<int, string>> pq;
	set<string> visited;
	process(start, visited, pq, network);
	int cost = 0;

	while(!pq.empty()){
		auto u = pq.top(); pq.pop();

		if(visited.find(u.second) == visited.end()){
			cost += (u.first * -1);
			process(u.second, visited, pq, network);
		}
	}

	return cost;
}

int main() {
	int C;
	cin >> C;

	for(int i = 0; i < C; i++){
		int M, N;
		cin >> M >> N;

		map<string, vector<pair<string, int>>> network;
		string start;

		for(int i = 0; i < N; i++){
			string u, v;
			int w;
			cin >> u >> v >> w;

			start = u;
			network[u].push_back(make_pair(v, w));
			network[v].push_back(make_pair(u, w));
		}

		int answer = Prim(network, start);
		cout << answer << endl << endl;
	}

	return 0;
}

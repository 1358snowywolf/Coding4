#include <bits/stdc++.h>

using namespace std;
map<int, vector<pair<int, int>>> graph;

vector<int> Dijkstra(int N, int start){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (N, 1076000);
	pq.push(make_pair(0, start));
	distance[start] = 0;

	while(!pq.empty()){
		pair<int, int> front = pq.top();
		pq.pop();

		if(front.first * -1 > distance[front.second]){
			continue;
		}

		for(auto n : graph[front.second]){
			if(distance[front.second] + n.second < distance[n.first]){
				distance[n.first] = distance[front.second] + n.second;
				pq.push(make_pair(distance[n.first] * -1, n.first));
			}
		}
	}

	return distance;
}

int main() {
	int C;
	cin >> C;

	for(int i = 1; i <= C; i++){
		graph.clear();
		int N, M, S, E;
		cin >> N >> M >> S >> E;

		for(int i = 0; i < N; i++){
			graph.insert(make_pair(i, vector<pair<int, int>> ()));
		}

		for(int i = 0; i < M; i++){
			int u, v, weight;
			cin >> u >> v >> weight;
			graph[u].push_back(make_pair(v, weight));
			graph[v].push_back(make_pair(u, weight));
		}

		vector<int> distance = Dijkstra(N, S);
		cout << "Case #" << i << ": ";

		if(distance[E] == 1076000){
			cout << "unreachable" << endl;
		}
		else{
			cout << distance[E] << endl;
		}
	}


	return 0;
}

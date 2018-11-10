#include <bits/stdc++.h>

using namespace std;
map<int, vector<pair<int, int>>> graph;

vector<int> bellmanFord(int N, int start){
	vector<int> distance (N, 200000);
	distance[start] = 0;

	for(int i = 0; i < N; i++){
		for(auto u : graph){
			for(auto neighbors : u.second){
				distance[neighbors.first] = min(distance[neighbors.first], distance[u.first] + neighbors.second);
			}

//			for(int i = 0; i < (int) distance.size(); i++){
//				cout << distance[i] << " ";
//			}
//
//			cout << endl;
		}
	}

	return distance;
}

int main() {
	int T, C, start, end;
	cin >> T >> C >> start >> end;

	for(int i = 0; i < T; i++){
		graph.insert(make_pair(i, vector<pair<int, int>> ()));
	}

	for(int i = 0; i < C; i++){
		int u, v, weight;
		cin >> u >> v >> weight;

		graph[u - 1].push_back(make_pair(v-1, weight));
		graph[v - 1].push_back(make_pair(u-1, weight));
	}

	vector<int> distance = bellmanFord(T, start - 1);
	cout << distance[end - 1] << endl;

	return 0;
}

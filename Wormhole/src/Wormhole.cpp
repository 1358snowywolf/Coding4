//============================================================================
// Name        : Wormhole.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> graph;

bool bellmanFord(int N){
	vector<int> distance (N, 200000);
	distance[0] = 0;
	int i = 0;

	for(; i < N; i++){
		bool changed = false;

		for(auto u : graph){
			for(auto neighbors : u.second){
				if(distance[neighbors.first] > distance[u.first] + neighbors.second){
					distance[neighbors.first] = distance[u.first] + neighbors.second;
					changed = true;
				}
			}
		}

		if(!changed){
			break;
		}
	}

	return (i == N);
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		int N, M;
		cin >> N >> M;
		graph.clear();

		for(int i = 0; i < N; i++){
			graph.insert(make_pair(i, vector<pair<int, int>> ()));
		}

		for(int i = 0; i < M; i++){
			int u, v, weight;
			cin >> u >> v >> weight;

			graph[u].push_back(make_pair(v, weight));
		}

		bool goBack = bellmanFord(N);

		if(goBack){
			cout << "possible" << endl;
		}
		else{
			cout << "not possible" << endl;
		}
	}
	return 0;
}

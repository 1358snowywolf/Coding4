#include <bits/stdc++.h>

using namespace std;
map<int, vector<pair<int, int>>> graph;
set<int> question;

vector<int> bellmanFord(int N){
	vector<int> distance (N, 2000000);
	vector<int> previous;
	distance[0] = 0;
	int i;

	for(i = 0; i < N; i++){
		bool changed = false;
		previous = distance;

		for(auto u : graph){
			for(auto neighbors : u.second){
				if(distance[neighbors.first] > distance[u.first] + neighbors.second && distance[u.first] != 2000000){
					distance[neighbors.first] = distance[u.first] + neighbors.second;
					changed = true;
				}
			}
		}

		if(!changed) break;
	}

	if(i == N){
		for(auto u : graph){
			for(auto neighbors : u.second){
				if(distance[neighbors.first] > distance[u.first] + neighbors.second && distance[u.first] != 2000000){
					distance[neighbors.first] = distance[u.first] + neighbors.second;
				}
			}
		}

		for(int j = 0; j < N; j++){
			if(distance[j] != previous[j]){
				question.insert(j);
			}
		}
	}

	return distance;
}

int find(vector<int> junctions, int u, int v){
	return (junctions[v] - junctions[u]) * (junctions[v] - junctions[u]) * (junctions[v] - junctions[u]);
}

int main() {
	int N;
	int index = 1;

	while(cin >> N){
		graph.clear();
		question.clear();
		vector<int> junctions (N, 0);
		int M, P;

		for(int i = 0; i < N; i++){
			int cost;
			cin >> cost;
			junctions[i] = cost;
			graph.insert(make_pair(i, vector<pair<int, int>> ()));
		}

		cin >> M;

		for(int i = 0; i < M; i++){
			int u, v;
			cin >> u >> v;
			graph[u - 1].push_back(make_pair(v - 1, find(junctions, u - 1, v - 1)));
		}

		auto distance = bellmanFord(N);
		cout << "Set #" << index << endl;

		cin >> P;

		for(int i = 0; i < P; i++){
			int end;
			cin >> end;

			if(question.find(end - 1) != question.end() || distance[end - 1] < 3 || distance[end - 1] == 2000000){
				cout << "?" << endl;
			}
			else{
				cout << distance[end - 1] << endl;
			}
		}

		index++;
	}
	return 0;
}

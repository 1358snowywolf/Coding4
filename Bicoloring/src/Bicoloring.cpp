#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;

bool DFS(vector<int> color, int index, int prev){
	if(prev != -1){
		color[index] = (color[prev] == 1) ? 2 : 1;
	}

	for(int v : graph[index]){
		if(color[v] == color[index]) return false;
		if(color[v] != 0) continue;
		bool work = DFS(color, v, index);
		if(!work) return false;
	}

	return true;
}

int main() {
	int N, M;

	while(true){
		cin >> N;
		if(N == 0) break;
		cin >> M;
		graph.clear();

		for(int i = 0; i < M; i++){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<int> color (N, 0);
		set<int> visited;
		visited.insert(0);
		color[0] = 1;

		if(DFS(color, 0, -1)){
			cout << "BICOLORABLE." << endl;
		}
		else{
			cout << "NOT BICOLORABLE." << endl;
		}
	}

	return 0;
}

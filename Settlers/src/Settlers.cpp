#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
int current = 0;

void DFS(set<pair<int, int>> visited, int index, int prev, int length){
	if(visited.find(make_pair(prev, index)) != visited.end() || visited.find(make_pair(index, prev)) != visited.end()) return;
	visited.insert(make_pair(prev, index));
	visited.insert(make_pair(index, prev));

//	cout << prev << " " << index << endl;

	current = max(current, length);

	for(auto i : graph[index]){
		DFS(visited, i, index, length + 1);
	}
}

int main() {
	int N, M, s, e;

	while(true){
		graph.clear();
		cin >> N >> M;

		if(N == 0 && M == 0) break;

		for(int i = 0; i < M; i++){
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		int maximum = 0;

		for(int i = 0; i < N; i++){
			DFS(set<pair<int, int>> (), i, i, 0);
			maximum = max(maximum, current);
			current = 0;
		}

		cout << maximum << endl;
	}

	return 0;
}

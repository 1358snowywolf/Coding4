#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;

bool DFS(vector<int> colors, int index, int prev){
	if(prev != -1){
		colors[index] = (colors[prev] == 1) ? 2 : 1;
	}

	if(colors[index] == 2){
		for(int i : graph[index]){
			if(colors[i] == 2) return false;
			bool works = DFS(colors, i, index);
			if(!works) return false;
		}
	}
	else{
		for(int i : graph[index]){
			if(colors[i] == 1) return false;
			bool works = DFS(colors, i, index);
			if(!works) return false;
		}
	}

	return true;
}

int main() {
	int V, u, v;

	while(true){
		cin >> V;
		if(V == 0) break;
		graph.clear();

		while(true){
			cin >> u >> v;
			if(u == 0 && v == 0) break;
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> colors (V, 0);
		colors[0] = 1;

		if(DFS(colors, 0, -1)){
			cout << "YES" << endl;
			continue;
		}

		colors[0] = 2;
		if(DFS(colors, 0, -1)){
			cout << "YES" << endl;
			continue;
		}

		cout << "NO" << endl;
	}

	return 0;
}

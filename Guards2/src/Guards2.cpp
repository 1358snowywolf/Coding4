#include <bits/stdc++.h>

#define N 210

using namespace std;
map<int, vector<int>> graph;
//vector<vector<int>> graph;
int CC;
int color[N];

int DFS(int u){
//	cout << u << "  " << color[u] << endl;
	int count = 0;

	for(int v : graph[u]){
//		visited.insert(v);

		if(color[v] == color[u]) return -1;
		if(color[v] != 0){
			continue;
		}

		color[v] = color[u] * -1;
		int tmp = DFS(v);
//		cout << v << ": " << tmp << endl;

		if(tmp == -1) return -1;
		count += tmp;
	}

	count += (color[u] == 1) ? 1 : 0;
	CC++;
	return count;
}

int main() {
	int T, u, v, verticies, edges;
	cin >> T;

	for(int times = 0; times < T; times++){
		graph.clear();
		cin >> verticies >> edges;

		if(edges == 0){
			cout << verticies << endl;
			continue;
		}

		for(int i = 0; i < edges; i++){
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		int result = 0;
		int i;
		memset(color, 0, sizeof(color));

		for(i = 0; i < verticies; i++){
			if(color[i] != 0) continue;
			CC = 0;

			color[i] = 1;
			int tmp = DFS(i);


			if(tmp == -1){
				cout << tmp << endl;
				break;
			}

			result += (CC - tmp == 0 ? CC : min(tmp, CC - tmp));

//			cout << i << "    " << tmp << "   " << CC << " " << result << endl;
		}

		if(i == verticies){
			cout << result << endl;
		}

//		cout << result << endl;
	}


	return 0;
}

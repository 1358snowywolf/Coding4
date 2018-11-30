#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
set<int> remaining;

int DFS(vector<int>& colors, int index, int prev){
	int used = 0;
//	cout << index << endl;

	if(prev != -1){
		colors[index] = (colors[prev] == 1) ? 2 : 1;
	}

	if(colors[index] == 1) used++;

	for(int i : graph[index]){
		if(colors[i] == colors[index]) return 0;
	}

	int minimum = INT_MAX;

	for(int i : graph[index]){
		if(i == prev) continue;
		if(colors[i] != 0) continue;
		colors[i] = colors[prev];
		remaining.erase(i);

		int backup = used;
		int guards = DFS(colors, i, index);

		if(guards == 0) return 0;
		minimum = min(minimum, used);
		used = backup;
	}

	return used;
}

//bool DFS(vector<int>& colors, int index, int prev){
//	if(prev != -1){
//		colors[index] = (colors[prev] == 1) ? 2 : 1;
//	}
//
//	for(int i : graph[index]){
//		if(colors[i] == colors[index]) return false;
//	}
//
//	for(int i : graph[index]){
//		if(i == prev) continue;
//		if(colors[i] != 0) continue;
//		colors[i] = colors[prev];
//		bool work = DFS(colors, i, index);
//		if(!work) return false;
//	}
//
//	return true;
//}


int main() {
	int T, u, v, verticies, edges;
	cin >> T;

	for(int times = 0; times < T; times++){
		graph.clear();
		remaining.clear();
		cin >> verticies >> edges;

		for(int i = 0; i < edges; i++){
			cin >> u >> v;

			remaining.insert(u);
			remaining.insert(v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<int> colors (verticies, 0);
		int minimum = 0;
		int i;

		for(i= 0; i < verticies; i++){
			if(remaining.find(i) == remaining.end()) continue;
			colors[i] = 1;
			int used = 0;
			int answer = DFS(colors, i, -1);
			colors[i] = 0;

			if(answer == -1){
				cout << "-1" << endl;
				break;
			}

			minimum += used;
//			cout << minimum << endl;
		}

		if(i == verticies){
			cout << minimum << endl;
		}

	}

	return 0;
}

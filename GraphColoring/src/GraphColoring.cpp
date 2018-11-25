#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
vector<int> answer;

bool canbeBlack(set<int> black, int u){
	for(int v : graph[u]){
		if(black.find(v) != black.end()){
			return false;
		}
	}

	return true;
}

void DFS(set<int>& visited, set<int> black, string previous, int index){
	visited.insert(index);

		for (auto i : visited) {
			cout << i << " ";
		}
		cout << endl;
		for(auto i : black){
			cout << i << " ";
		}

		cout << endl;
		cout << " ---------------------- " << endl;

	if(visited.size() == graph.size()){
		if(answer.size() < black.size()){
//			answer (black.begin(), black.end());
			vector<int> input (black.begin(), black.end());
			answer = input;
		}
		return;
	}
//	cout << index << endl;

	for(auto i : graph[index]){
		if(visited.find(i) != visited.end()){
			continue;
		}

		DFS(visited, black, "white", i);

		if(previous == "white" && canbeBlack(black, i)){
			black.insert(i);
			DFS(visited, black, "black", i);
		}
	}
}

int main(){
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		int N, K;
		cin >> N >> K;
//		cout << N << " " << K << endl;
		graph.clear();
		answer.clear();

		for(int i = 0; i < K; i++){
			int u, v;
			cin >> u >> v;

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		set<int> black;
		black.insert(0);

		for(auto u : graph){
			cout << u.first << ": ";

			for(auto v : u.second){
				cout << v << " ";
			}

			cout << endl;
		}

		cout << endl;
		set<int> visited;

//		DFS(set<int> (), black, "black", 0);
//		DFS(set<int> (), set<int> (), "white", 0);

		for(int i = 0; i < N; i++){
			if(visited.find(i) != visited.end()){
				continue;
			}

			auto backup = visited;

			DFS(visited, black, "black", 0);
			DFS(backup, set<int> (), "white", 0);
		}

		sort(answer.begin(), answer.end());

		cout << answer.size() << endl;
		for(int i = 0; i < (int) answer.size(); i++){
			cout << answer[i] + 1;

			if(i + 1 < (int) answer.size()){
				cout << " ";
			}
		}

		cout << endl;

//		for(int i = 0; i < (int) answer.size() - 1; i++){
//			cout << answer[i] + 1 << " ";
//		}
//		cout << answer[(int) answer.size() - 1] + 1 << endl << endl;
	}


	return 0;
}

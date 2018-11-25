#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
vector<int> answer;

bool check(set<int> black){
	for(auto u : graph){
		if(black.find(u.first) == black.end()){
			continue;
		}

		for(int v : u.second){
			if(black.find(v) != black.end()){
				return false;
			}
		}
	}

	return true;
}

void DFS(int index, int N, set<int> black){
	if(!check(black)){
		return;
	}

	if(index == N - 1){
		if(check(black)){
			if(answer.size() < black.size()){
				vector<int> input (black.begin(), black.end());
				answer = input;
			}
		}
		return;
	}

	index++;

	DFS(index, N, black);
	black.insert(index);
	DFS(index, N, black);
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		int N, K;
		cin >> N >> K;
		graph.clear();
		answer.clear();

		for(int i = 0; i < K; i++){
			int u, v;
			cin >> u >> v;

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		DFS(-1, N, set<int> ());

		cout << answer.size() << endl;
		for(int i = 0; i < (int) answer.size(); i++){
			cout << answer[i] + 1;

			if(i + 1 < (int) answer.size()){
				cout << " ";
			}
		}

		cout << endl;

	}

	return 0;
}

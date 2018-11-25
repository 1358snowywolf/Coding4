#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
//vector<int> indegrees;
vector<int> answer;
set<int> visited;

void topLogical(int u){
	if(visited.find(u) != visited.end()){
		return;
	}

	visited.insert(u);

	for(auto i : graph[u]){
		topLogical(i);
	}

	answer.push_back(u);
}

int main() {
	int N, M;

	while(true){
		cin >> N >> M;
		if(N == 0 && M == 0) break;

		graph.clear();
		answer.clear();
		visited.clear();
//		indegrees.clear();

//		vector<int> sub (N, 0);
//		indegrees = sub;

		for(int i = 0; i < M; i++){
			int u, v;
			cin >> u >> v;
			graph[u - 1].push_back(v - 1);
//			indegrees[v - 1]++;
		}

//		for(int i = 0; i < N; i++){
//			if(indegrees[i] == 0){
//				topLogical(i);
//				break;
//			}
//		}

//		topLogical(0);

		for(int i = 0; i < N; i++){
			if(visited.find(i) == visited.end()){
				topLogical(i);
			}
		}

		reverse(answer.begin(), answer.end());

		for(int i = 0; i < N - 1; i++){
			cout << answer[i] + 1 << " ";
		}

		cout << answer[N - 1] + 1 << endl;
	}

	cout << endl;

	return 0;
}

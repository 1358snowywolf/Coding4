#include <bits/stdc++.h>

using namespace std;
bool work = false;

void DFS(vector<pair<int, int>> dominoes, pair<int, int> end, vector<bool> visited, int index, int current, int N, pair<int, int> use){
	if(work) return;
	if(index > N) return;

	if(index == N){
		if(use.second == end.first){
			work = true;
		}

		return;
	}

	cout << use.first << " " << use.second << endl;
	visited[current] = true;
	index++;

	for(int i = 0; i < (int) dominoes.size(); i++){
		if(visited[i]) continue;

		if(use.second == dominoes[i].first){
			DFS(dominoes, end, visited, index, i, N, dominoes[i]);
		}
		if(use.second == dominoes[i].second){
			DFS(dominoes, end, visited, index, i, N, make_pair(dominoes[i].second, dominoes[i].first));
		}
	}
}

int main() {
	int N, M;

	while(true){
		cin >> N;
		if(N == 0) break;
		cin >> M;
		work = false;

		vector<pair<int, int>> dominoes;
		pair<int, int> start, end;

		cin >> start.first >> start.second >> end.first >> end.second;

		for(int i = 0; i < M; i++){
			int f, s;
			cin >> f >> s;
			dominoes.push_back(make_pair(f, s));
		}

		DFS(dominoes, end, vector<bool> (M + 1, false), 0, M, N, start);

		if(work){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

	return 0;
}

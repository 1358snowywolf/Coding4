#include <bits/stdc++.h>
#define MAX_N 40100;
using namespace std;
vector<vector<int>> graph;


vector<int> BFS(int N, int start){
	vector<int> distance (N, -10);
	int count = 1;
	queue<int> q;

	q.push(start);
	q.push(-1);
	distance[start] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();
//		cout << u << endl;

		if(u == -1){
			count++;
			if(!q.empty()) q.push(-1);
			continue;
		}

		for(int v : graph[u]){
			if(distance[v] != -10) continue;
			distance[v] = count;
			q.push(v);
		}
	}

	return distance;
}

int main() {
	int B, E, P, N, M, u, v;
	cin >> B >> E >> P >> N >> M;

	graph.assign(N, vector<int> ());

	for(int i = 0; i < M; i++){
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	auto bessie = BFS(N, 0);
	auto elsie = BFS(N, 1);
	auto partner = BFS(N, N - 1);

//	for(int i = 0; i < N; i++){
//		cout << bessie[i] << " ";
//	}
//	cout << endl << "......................" << endl;
//
//	for(int i = 0; i < N; i++){
//		cout << elsie[i] << " ";
//	}
//	cout << endl << "......................" << endl;
//
//	for(int i = 0; i < N; i++){
//		cout << partner[i] << " ";
//	}
//	cout << endl << "......................" << endl;

	int minimum = INT_MAX;

	for(int i = 0; i < N; i++){
		minimum = min(minimum, (bessie[i] * B) + (elsie[i] * E) + (partner[i] * P));
	}

	cout << minimum << endl;

	return 0;
}

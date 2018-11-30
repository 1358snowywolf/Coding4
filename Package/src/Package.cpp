#include <bits/stdc++.h>
#define INF 200000000

using namespace std;
vector<vector<pair<int, int>>> graph;

vector<int> Dijkstra(){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (graph.size(), INF);
	pq.push(make_pair(0, 0));
	distance[0] = 0;

	while(!pq.empty()){
		pair<int, int> u = pq.top(); pq.pop();
//		cout << u.first * -1 << " " << u.second << endl;

//		for(int i = 0; i < (int) distance.size(); i++){
//			if(distance[i] == 2000000) cout << "X ";
//			else cout << distance[i] << " ";
//		}
//
//		cout << endl;

		if(u.first * -1 > distance[u.second]){
			continue;
		}

		for(auto v : graph[u.second]){
			if(distance[u.second] + v.second < distance[v.first]){
				distance[v.first] = distance[u.second] + v.second;
				pq.push(make_pair(distance[v.first] * -1, v.first));
			}
		}
	}

	return distance;
}

int main(){
	int N, M;
	cin >> N >> M;
	graph.assign(N, vector<pair<int, int>> ());

	for(int i = 0; i < M; i++){
		int u, v, w;
		cin >> u >> v >> w;

		graph[u - 1].push_back(make_pair(v - 1, w));
		graph[v - 1].push_back(make_pair(u - 1, w));
	}

//	for(int i = 0; i < graph.size(); i++){
//		cout << i + 1 << ": ";
//
//		for(auto j : graph[i]){
//			cout << "(" << j.first + 1 << ", " << j.second << ") ";
//		}
//
//		cout << endl;
//	}

	auto distance = Dijkstra();
	cout << distance[N - 1] << endl;

	return 0;
}

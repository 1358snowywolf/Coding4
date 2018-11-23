#include <bits/stdc++.h>

using namespace std;

int main(){
	int D, P, C, F, S;
	cin >> D >> P >> C >> F >> S;
	vector<int> distance (C, 2000000);
	map<int, vector<pair<int, int>>> graph;

	for(int i = 0; i < P; i++){
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(make_pair(v - 1, 0));
	}

	for(int i = 0; i < F; i++){
		int u, v, w;
		cin >> u >> v >> w;

		graph[u - 1].push_back(make_pair(v - 1, w * -1));
	}

	distance[S - 1] = D * -1;

	for(int i = 0; i < C; i++){
		for(auto u : graph){
			for(auto v : u.second){
				distance[v.first] = min(distance[v.first], distance[u.first] + (v.second * -1) - D);
			}
		}
	}

//	for(auto u : graph){
//		cout << u.first << ": ";
//		for(auto v : graph[u.first]){
//			cout << "(" << v.first << ", " << v.second << ") ";
//		}
//
//		cout << endl;
//	}

//	for(int i = 0; i < C; i++){
//		cout << distance[i] << " ";
//	}
//
//	cout << endl;

	int maximum = 0;

	for(int i = 0; i < C; i++){
		maximum = max(maximum, distance[i] * -1);
//		cout << distance[i] * -1 << " ";
	}

//	cout << endl;

	cout << maximum << endl;

	return 0;
}

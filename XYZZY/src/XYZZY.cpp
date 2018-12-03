#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> energy;

bool difference(vector<int> copy, vector<int> distance){
	for(int i = 0; i < (int) copy.size(); i++){
		if(copy[i] != distance[i]) return true;
	}

	return false;
}

bool bellmanFord(){
	vector<int> distance (graph.size(), 200000000);
	distance[0] = -100;

	for(int i = 0; i < (int) distance.size(); i++){
//		bool changed = false;
		auto copy = distance;

		for(int j = 0; j < (int) graph.size(); j++){
			cout << distance[j] << " ";
		}
		cout << endl;

		for(int u = 0; u < (int) distance.size(); u++){
			for(auto j : graph[u]){
//				if(distance[j] > distance[u] + energy[j]){
//					changed = true;
//				}

				distance[j] = min(distance[j], distance[u] + energy[j]);
				if(distance[j] > 0){
//					changed = false;
					distance[j] = 200000000;
				}
			}
		}
//
//		if(!changed) break;
//		if(changed && i == (int) distance.size() - 1){
//			return true;
//		}

		if(difference(copy, distance) && i == (int) distance.size() - 1){
			return true;
		}
	}

	if(distance[(int) distance.size() - 1] == 200000000 || distance[(int) distance.size() - 1] * -1 <= 0){
		return false;
	}

	return true;
}

int main(){
	int N;

	while(true){
		cin >> N;
		if(N == -1) break;
		graph.clear();
		energy.clear();

		graph.assign(N, vector<int> ());
		energy.assign(N, int ());

		for(int i = 0; i < N; i++){
			int e, M;
			cin >> e >> M;
			energy[i] = e * -1;
			for(int j = 0; j < M; j++){
				int v;
				cin >> v;
				graph[i].push_back(v - 1);
			}
		}

//		for(int i = 0; i < N; i++){
//			cout << i << ": ";
//
//			for(int j : graph[i]){
//				cout << j << ", ";
//			}
//
//			cout << endl;
//		}
//
//		for(int i = 0; i < N; i++){
//			cout << energy[i] << " ";
//		}
//
//		cout << endl << endl;

		bool result = bellmanFord();

		if(result){
			cout << "winnable" << endl;
		}
		else{
			cout << "hopeless" << endl;
		}
	}

	return 0;
}

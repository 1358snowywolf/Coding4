#include <bits/stdc++.h>

using namespace std;
//map<int, vector<pair<int, int>>> graph;
//vector<bool> visited;
vector<int> parents;
long long total = 0;
//long long MST_cost = 0;

int findParents(int u){
//	while(parents[u] != u){
//		u = parents[u];
//	}
//
//	return u;
	return ((parents[u] == u) ? u : (parents[u] = findParents(parents[u])));
}

void connect(int u, int v){
	int x = findParents(u);
	int y = findParents(v);

	parents[y] = x;
}

void KrushalAlgorithm(vector<tuple<long long, int, int>> edges){
	for(tuple<int, int, int> edge : edges){
		int weight, u, v;
		tie(weight, u, v) = edge;

		if(findParents(u) != findParents(v)){
			connect(u, v);
			total += weight;
		}
	}
}

//void process(int u, priority_queue<pair<int, int>>& pq){
//	visited[u] = true;
//
//	for(pair<int, int> n : graph[u]){
//		if(!visited[n.first]){
//			pq.push(make_pair(n.second, n.first));
//		}
//	}
//}
//
//void Prim(){
//	priority_queue<pair<int, int>> pq;
//	process(0, pq);
//
//	while(!pq.empty()){
//		pair<int, int> u = pq.top();
//		pq.pop();
//
//		if(!visited[u.second]){
//			MST_cost += (u.first);
//		}
//
//		process(u.second, pq);
//	}
//}

int main() {
//	int N;
//	cin >> N;
//	vector<int> ID;
//	vector<tuple<long long, int, int>> edges;
//
//	for(int i = 0; i < N; i++){
//		int input;
//		cin >> input;
//		ID.push_back(input);
//		parents.push_back(i);
////		graph.insert(make_pair(i, vector<pair<int, int>> ()));
//	}
//
////	visited.assign(graph.size(), false);
//
//	for(int i = 0; i < N; i++){
//		for(int j = i + 1; j < N; j++){
//			int XOR = ID[i] ^ ID[j];
//			edges.push_back(make_tuple(XOR, i, j));
////			graph[i].push_back(make_pair(j, XOR));
////			graph[j].push_back(make_pair(i, XOR));
//		}
//	}
//
//	sort(edges.rbegin(), edges.rend());
////	Prim();
//	KrushalAlgorithm(edges);
//
//	cout << total << endl;
////	cout << MST_cost << endl;

	int N;
	cin >> N;
	vector<int> A;

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		A.push_back(input);
	}

	long long result = 0;
	vector<bool> used (N, false);
	vector<int> D (N, 0);

	for(int i = 0; i < N; i++){
		int j = -1;
		for(int k = 0; k < N; k++){
			if(used[k]){
				continue;
			}
			if(j == -1 || D[k] > D[j]){
				j = k;
			}
		}

		result += D[j];
		used[j] = true;

		for(int k = 0; k < N; k++){
			D[k] = max(D[k], A[i] ^ A[k]);
		}
	}

	cout << result << endl;

	return 0;
}

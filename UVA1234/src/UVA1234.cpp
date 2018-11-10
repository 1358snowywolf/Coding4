#include <bits/stdc++.h>

using namespace std;
vector<int> parents;
int total = 0;

int findParents(int u){
	while(parents[u] != u){
		u = parents[u];
	}

	return u;
}

void connect(int u, int v){
	int x = findParents(u);
	int y = findParents(v);

	parents[y] = x;
}

void KrushalAlgorithm(vector<tuple<int, int, int>> edges){
	for(tuple<int, int, int> edge : edges){
		int weight, u, v;
		tie(weight, u, v) = edge;

		if(findParents(u) != findParents(v)){
			connect(u, v);
			total += weight;
//			cout << "weight" << weight << endl;
		}
	}
}


int main() {
	int C;
	cin >> C;

	for(int i = 0; i < C; i++){
		parents.clear();
		total = 0;
		int N, M;
		cin >> N >> M;
		int maxWeight = 0;
		vector<tuple<int, int, int>> edges;

		for(int j = 0; j < M; j++){
			int start, end, weight;
			cin >> start >> end >> weight;
			edges.push_back(make_tuple(weight, start - 1, end - 1));
			maxWeight += weight;
		}

		for(int i = 0; i < N; i++){
			parents.push_back(i);
		}

		sort(edges.rbegin(), edges.rend());
		KrushalAlgorithm(edges);

		cout << maxWeight - total << endl;
//		cout << total << endl;
	}

	int zero;
	cin >> zero;
	return 0;
}

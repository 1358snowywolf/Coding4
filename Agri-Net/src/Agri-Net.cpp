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
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<tuple<int, int, int>> edges;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int weight;
			cin >> weight;

			if(i > j){
				edges.push_back(make_tuple(weight, i, j));
			}
		}

		parents.push_back(i);
	}

	sort(edges.begin(), edges.end());
	KrushalAlgorithm(edges);

	cout << total << endl;

	return 0;
}

#include <bits/stdc++.h>

using namespace std;
vector<int> parents;
vector<int> used;
int total = 0;
int N, M;

int findParents(int u){
	return ((parents[u] == u) ? u : (parents[u] = findParents(parents[u])));
}

void connect(int u, int v){
	int x = findParents(u);
	int y = findParents(v);

	parents[x] = y;
}

void Krushal(vector<tuple<int, int, int>> edges, int i){
	int counter = 0;

	for(int j = 0; j < (int) edges.size(); j++){
		if(i == j){
			continue;
		}

		int weight, u, v;
		tie(weight, u, v) = edges[j];

		if(findParents(u) != findParents(v)){
			connect(u, v);
			total += weight;
			counter++;

			if(i == -1){
				used.push_back(j);
			}
		}
	}

	if(counter < N - 1){
		total = INT_MAX;
	}
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		total = 0;
		used.clear();
		parents.clear();
		vector<tuple<int, int, int>> edges;

		cin >> N >> M;
//		cout << N << " " << M << endl;

		for(int i = 0; i < N; i++){
			parents.push_back(i);
		}

		for(int i = 0; i < M; i++){
			int start, end, weight;
			cin >> start >> end >> weight;
			edges.push_back(make_tuple(weight, start - 1, end - 1));
		}

		sort(edges.begin(), edges.end());
		Krushal(edges, -1);

		cout << total << " ";
		int maximum = INT_MAX;

		for(int i = 0; i < (int) used.size(); i++){
			total = 0;
			parents.clear();
			for(int i = 0; i < N; i++){
				parents.push_back(i);
			}

			Krushal(edges, used[i]);
//			cout << total << endl;
			maximum = min(maximum, total);
		}

		cout << maximum << endl;
	}
	return 0;
}

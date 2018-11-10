#include <bits/stdc++.h>

using namespace std;
vector<int> parents;
vector<int> size;
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

	if(size[y] < size[x]){
		parents[y] = x;
		size[y] += size[x];
	}
	else{
		parents[x] = y;
		size[x] += size[y];
	}
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
	int N, C;
	cin >> N >> C;
	size.assign(N, 1);
	vector<pair<int, int>> coordinates;
	vector<tuple<int, int, int>> edges;

	for(int i = 0; i < N; i++){
		int first, second;
		cin >> first >> second;

		parents.push_back(i);
		coordinates.push_back(make_pair(first, second));
	}

	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			int distance = (coordinates[i].first - coordinates[j].first) * (coordinates[i].first - coordinates[j].first) +
					(coordinates[i].second - coordinates[j].second) * (coordinates[i].second - coordinates[j].second);

			if(distance >= C){
				edges.push_back(make_tuple(distance, i, j));
			}
		}
	}

	sort(edges.begin(), edges.end());
	KrushalAlgorithm(edges);

	cout << total << endl;

	return 0;
}

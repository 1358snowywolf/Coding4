#include <bits/stdc++.h>

using namespace std;

void findPath(vector<vector<int>> parents, vector<int>& path, int i, int j){
	if(i != j){
		findPath(parents, path, i, parents[i][j]);
	}

	path.push_back(j);
}

bool includeHub(vector<int> path, int K){
	for(int i = 0; i < (int) path.size(); i++){
		if(path[i] < K){
			return true;
		}
	}

	return false;
}

int main() {
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	vector<vector<int>> parents (N, vector<int> (N, 0));
	vector<vector<long long>> weights (N, vector<long long> (N, LLONG_MAX));

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			parents[i][j] = i;
		}
	}

	for(int i = 0; i < M; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		weights[u - 1][v - 1] = w;
	}

	for(int i = 0; i < N; i++){
		weights[i][i] = 0;
	}

	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(weights[i][k] != LLONG_MAX && weights[k][j] != LLONG_MAX && weights[i][k] + weights[k][j] < weights[i][j]){
					parents[i][j] = parents[k][j];
					weights[i][j] = weights[i][k] + weights[k][j];
				}
			}
		}
	}

	int work = 0;
	long long total = 0;

	for(int i = 0; i < Q; i++){
		int u, v;
		cin >> u >> v;
		vector<int> path;
		findPath(parents, path, u - 1, v - 1);

		if(weights[u - 1][v - 1] != LLONG_MAX && includeHub(path, K)){
			work++;
			total += weights[u - 1][v - 1];
		}
	}

	cout << work << endl << total << endl;

	return 0;
}

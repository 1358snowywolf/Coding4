#include <bits/stdc++.h>

using namespace std;

int findParents(int u, vector<int> parents){
	return ((parents[u] == u) ? u : parents[u] = findParents(parents[u], parents));
}

void connect(int u, int v, vector<int>& parents){
	auto x = findParents(u, parents);
	auto y = findParents(v, parents);
	parents[x] = y;
}

int main() {
	int N, M;

	while(true){
		cin >> N >> M;
		if(N == 0 && M == 0) break;

//		cout << N << " " << M << endl;

		vector<tuple<int, int, int>> edges;

		for(int i = 0; i < M; i++){
			int u, v, w;
			cin >> u >> v >> w;
			edges.push_back(make_tuple(w, u, v));
		}

		sort(edges.begin(), edges.end());
		set<tuple<int, int, int>> used;
		vector<int> parents;

		for(int i = 0; i < N; i++){
			parents.push_back(i);
		}

		for(auto edge : edges){
			int w, u, v;
			tie(w, u, v) = edge;

			if(findParents(u, parents) != findParents(v, parents)){
				used.insert(edge);
				connect(u, v, parents);
			}
		}

		vector<int> answers;

		for(auto edge: edges){
			if(used.find(edge) == used.end()){
				int w, u, v;
				tie(w, u, v) = edge;
				answers.push_back(w);
			}
		}

		if(answers.empty()){
			cout << "forest" << endl;
		}
		else{
			for(int i = 0; i < (int) answers.size(); i++){
				cout << answers[i];

				if(i + 1 != (int) answers.size()){
					cout << " ";
				}
			}

			cout << endl;
		}
	}

	return 0;
}

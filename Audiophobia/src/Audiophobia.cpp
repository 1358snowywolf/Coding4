#include <bits/stdc++.h>

using namespace std;
vector<int> parents;


int findParents(int u){
	return ((parents[u] == u) ? u : parents[u] = findParents(parents[u]));
}

void connect(int u, int v){
	int x = findParents(u);
	int y = findParents(v);

	parents[x] = y;
}

int Krushal(int C, vector<tuple<int, int, int>> graph, int j, int k){
	for(int i = 0; i < C; i++){
		parents.push_back(i);
	}

	int maximum = 0;
	int times = 0;
//	bool usedj = false;
//	bool usedk = false;

	for(auto edge : graph){
		int w, u, v;
		times ++;
		tie(w, u, v) = edge;

//		if(u == j - 1 || v == j - 1){
//			usedj = true;
//		}
//		if(u == k - 1 || v == k - 1){
//			usedk = true;
//		}

		if(findParents(u) != findParents(v)){
			connect(u, v);
			maximum = max(maximum, w);
		}

//		if(usedj && usedk) return maximum;
//
//		if(times == (int) graph.size() - 1){
//			return -1;
//		}
	}

	return maximum;
}

int main() {
	int C, S, Q;
	int times = 1;

	while(true){
		parents.clear();
		cin >> C >> S >> Q;
		if(C == 0 && S == 0 && Q == 0) break;
		vector<tuple<int, int, int>> graph;

		for(int i = 0; i < S; i++){
			int u, v, w;
			cin >> u >> v >> w;
			graph.push_back(make_tuple(w, u - 1, v - 1));
		}

		cout << "Case #" << times << ":" << endl;
		sort(graph.begin(), graph.end());

		for(int i = 0; i < Q; i++){
			int j, k;
			cin >> j >> k;
			int answer = Krushal(C, graph, j, k);

			if(answer == -1){
				cout << "no path" << endl;
			}
			else{
				cout << answer << endl;
			}
		}

		cout << endl;
	}

	return 0;
}

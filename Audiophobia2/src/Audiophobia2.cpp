#include <bits/stdc++.h>

using namespace std;

int main() {
	int C, S, Q;
	int times = 1;

	while(true){
		cin >> C >> S >> Q;
		if(C == 0 && S == 0 && Q == 0) break;

		vector<vector<int>> graph (C, vector<int> (C, INT_MAX));

		for(int i = 0; i < S; i++){
			int u, v, w;
			cin >> u >> v >> w;
			graph[u - 1][v - 1] = w;
			graph[v - 1][u - 1] = w;
		}

		for(int i = 0; i < C; i++){
			graph[i][i] = 0;
		}

		for(int k = 0; k < C; k++){
			for(int i = 0; i < C; i++){
				for(int j = 0; j < C; j++){
					graph[i][j] = min(graph[i][j], max(graph[i][k], graph[j][k]));
				}
			}
		}

		cout << "Case #" << times << endl;

		for(int i = 0; i < Q; i++){
			int u, v;
			cin >> u >> v;

			if(graph[u - 1][v - 1] == INT_MAX){
				cout << "no path" << endl;
			}
			else{
				cout << graph[u - 1][v - 1] << endl;
			}
		}

		cout << endl;
		times++;
	}


	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	for(int times = 1; times <= T; times++){
		int N, R;
		cin >> N >> R;
		vector<vector<int>> headquarters (N, vector<int> (N, 2000000));

		for(int i = 0; i < R; i++){
			int u, v;
			cin >> u >> v;

			headquarters[u][v] = 1;
			headquarters[v][u] = 1;
		}

		int start, end;
		cin >> start >> end;

		for(int i = 0; i < N; i++){
			headquarters[i][i] = 0;
		}

		for(int k = 0; k < N; k++){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					headquarters[i][j] = min(headquarters[i][j], headquarters[i][k] + headquarters[k][j]);
				}
			}
		}

		int maximum = 0;

		for(int i = 0; i < N; i++){
			maximum = max(maximum, headquarters[start][i] + headquarters[i][end]);
		}

		cout << "Case " << times << ": " << maximum << endl;
	}
	return 0;
}

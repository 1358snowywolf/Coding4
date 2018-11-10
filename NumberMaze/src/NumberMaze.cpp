#include <bits/stdc++.h>

using namespace std;

int main() {
	int C;
	cin >> C;

	for(int i = 0; i < C; i++){
		int N, M;
		cin >> N >> M;
		vector<vector<int>> maze;

		for(int j = 0; j < N; j++){
			vector<int> line;

			for(int j = 0; j < M; j++){
				int input;
				cin >> input;
				line.push_back(input);
			}

			maze.push_back(line);
		}

		for(int k = 0; k < N; k++){
			for(int j = 0; j < M; j++){
				if(k - 1 >= 0 && j - 1 >= 0){
					maze[k][j] = min(maze[k - 1][j], maze[k][j- 1]) + maze[k][j];
				}
				else if(k - 1 >= 0){
					maze[k][j] += maze[k - 1][j];
				}
				else if (j - 1 >= 0){
					maze[k][j] += maze[k][j - 1];
				}
			}
		}

		cout << maze[N - 1][M - 1] << endl;
	}

	cout << endl;

	return 0;
}

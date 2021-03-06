#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> maze;
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};

vector<vector<int>> Dijkstra(int N, int M){
	priority_queue<pair<int, pair<int, int>>> pq;
	vector<vector<int>> distance (N, vector<int> (M, 1076000));
	pq.push(make_pair(maze[0][0], make_pair(0, 1)));
	pq.push(make_pair(maze[0][0], make_pair(1, 0)));
	distance[0][0] = maze[0][0];

	while(!pq.empty()){
		pair<int, pair<int, int>> front = pq.top();
		pq.pop();

		int X = front.second.first;
		int Y = front.second.second;

		if(X < 0 || X >= (int) maze.size()){
			continue;
		}
		if(Y < 0 || Y >= (int) maze[X].size()){
			continue;
		}

		if(front.first * -1 > distance[X][Y]){
			continue;
		}


		if(distance[X][Y] > maze[X][Y] + front.first){
			distance[X][Y] = maze[X][Y] + front.first;

			for(int i = 0; i < 4; i++){
				pq.push(make_pair(distance[X][Y], make_pair(X + dx[i], Y + dy[i])));
			}
		}
	}

	return distance;
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		maze.clear();
		int N, M;
		cin >> N >> M;

		for(int i = 0; i < N; i++){
			vector<int> line;

			for(int j = 0; j < M; j++){
				int input;
				cin >> input;
				line.push_back(input);
			}

			maze.push_back(line);
		}

		auto distance = Dijkstra(N, M);
		cout << distance[N - 1][M - 1] << endl;
	}

	cout << endl;

	return 0;
}

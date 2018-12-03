#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> direction = {{0, 1}, {1, 0}};
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
map<int, vector<pair<int, int>>> graph;
int maxX, maxY;

void add(int i, int j, vector<vector<int>> labyrinth ){
	for(int k = 0; k < 4; k++){
		if(i + dx[k] < 0 || i + dx[k] >= maxX){
			continue;
		}
		if(j + dy[k] < 0 || j + dy[k] >= maxY){
			continue;
		}
		if(labyrinth[i + dx[k]][j + dy[k]] == 2){
			continue;
		}

		if(labyrinth[i + dx[k]][j + dy[k]] == 1){
			graph[(i * 1000) + j].push_back({((i + dx[k]) * 1000) + j + dy[k], 1});
		}
		else{
			graph[(i * 1000) + j].push_back({((i + dx[k]) * 1000) + j + dy[k], 0});
		}
	}
}

void makeGraph(vector<vector<int>> labyrinth){
	for(int i = 0; i < maxX; i++){
		for(int j = 0; j < maxY; j++){
			add(i, j, labyrinth);
		}
	}
}

int main(){
	int N, M;

	while(true){
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		vector<vector<int>> labyrinth (201, vector<int> (201, 0)); // 0 nothing 1 door 2 wall
		maxX = 0; maxY = 0;

		for(int i = 0; i < N; i++){
			int x, y, d, t;
			cin >> x >> y >> d >> t;
			maxX = max(maxX, x);
			maxY = max(maxY, y);

			for(int j = 0; j < t; j++){
				labyrinth[x + (direction[d].first * j)][y + (direction[d].second * j)] = 2;
			}
		}

		for(int i = 0; i < M; i++){
			int x, y, d;
			cin >> x >> y >> d;
			maxX = max(maxX, x);
			maxY = max(maxY, y);

			labyrinth[x + direction[d].first][y + direction[d].second] = 1;
		}

		makeGraph(labyrinth);

		for(auto i : graph){
			cout << i.first << ": ";

			for(auto j : i.second){
				cout << "(" << j.first << ", " << j.second << ") ";
			}

			cout << endl;
		}
	}

	return 0;
}

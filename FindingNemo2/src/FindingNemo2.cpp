#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> direction = {{1, 0}, {0, 1}};
vector<char> arr = {'.', '*', 'X'};
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

map<int, set<pair<int, int>>> makeGraph(vector<vector<int>> labyrinth, int maxX, int maxY){
	map<int, set<pair<int, int>>> graph;

	for(int i = 1; i < min(maxX, 401); i += 2){
		for(int j = 1; j < min(maxY, 401); j += 2){
//			if(i != 7 || j != 5){
//				continue;
//			}

			for(int k = 0; k < 4; k++){
				if(i + dx[k] < 0 || i + dx[k] >= 201){
					continue;
				}
				if(j + dy[k] < 0 || j + dy[k] >= 201){
					continue;
				}
				if(labyrinth[i + dx[k]][j + dy[k]] == 2){
					continue;
				}
				if(((i + dx[k] + dx[k]) * maxY) + j + dy[k] + dy[k] < 0 || ((i + dx[k] + dx[k]) * maxY) + j + dy[k] + dy[k] >= 201){
					continue;
				}


//				if(labyrinth[i + dx[k]][j + dy[k]] == 1){
					graph[(i * maxY) + j].insert(make_pair(((i + dx[k] + dx[k]) * maxY) + j + dy[k] + dy[k], labyrinth[i + dx[k]][j + dy[k]]));
					graph[((i + dx[k] + dx[k]) * maxY) + j + dy[k] + dy[k]].insert(make_pair((i * maxY) + j, labyrinth[i + dx[k]][j + dy[k]]));

//					cout << ((i + dx[k] + dx[k]) * maxX) + j + dy[k] + dy[k] << endl;
//				}
//				else{
//					graph[(i * maxX) + j].insert(make_pair((i * maxX) + dx[k] + dx[k] + j + dy[k] + dy[k], 0));
//					graph[(i * maxX) + dx[k] + dx[k] + j + dy[k] + dy[k]].insert(make_pair((i * maxX) + j, 0));
//				}
			}
		}
	}

	return graph;
}

vector<int> Dijkstra(map<int, set<pair<int, int>>> graph, int maxX, int maxY){
	priority_queue<pair<int, int>> pq;
//	map<int, int> distance;
	vector<int> distance (maxX * maxY, 200000000);
	pq.push(make_pair(0, maxY + 1));
	distance[maxY + 1] = 0;

//	cout << maxY + 1 << endl;

	while(!pq.empty()){
		pair<int, int> front = pq.top(); pq.pop();
		int d = front.first; int u = front.second;

		if(d * -1 > distance[front.second]){
			continue;
		}

//		cout << u << ": ";

		for(auto j : graph[u]){
			if(distance[u] + j.second < distance[j.first]){
				distance[j.first] = distance[u] + j.second;
				pq.push(make_pair(distance[j.first] * -1, j.first));
//				cout << j.first << ", ";
			}
		}

//		cout << endl;
	}

	return distance;
}

int main(){
	int N, M;

	while(true){
		int maxX = 0;
		int maxY = 0;

		cin >> N >> M;
		if(N == -1 && M == -1) break;

		if(N == 0 && M == 0){
			cout << 0 << endl;
			continue;
		}

		vector<vector<int>> labyrinth (401, vector<int> (401, 0));

		for(int i = 0; i < N; i++){
			int x, y, d, t;
			cin >> x >> y >> d >> t;
			x *= 2; y *= 2;
			maxX = max(maxX, x); maxY = max(maxY, y);

			for(int j = 0; j < t * 2; j++){
				labyrinth[x + (direction[d].first * j)][y + (direction[d].second * j)] = 2;
			}

//
//
//			for(int i = 0; i < 15; i++){
//				for(int j = 0; j < 15; j++){
//					cout << arr[labyrinth[i][j]];
//				}
//
//				cout << endl;
//			}
//
//			cout << endl << endl;
		}

		maxX += 3;
		maxY += 3;

		for(int i = 0; i < maxX; i++) {
			labyrinth[i][0] = 2;
			labyrinth[i][maxY - 1] = 2;
		}

		for(int i = 0; i< maxY; i++) {
			labyrinth[0][i] = 2;
			labyrinth[maxX - 1][i] = 2;
		}

		for(int i = 0; i < M; i++){
			int x, y, d;
			cin >> x >> y >> d;
			x *= 2; y *= 2;
			maxX = max(maxX, x); maxY = max(maxY, y);

//			labyrinth[x + direction[d].first][y + direction[d].second] = 1;
			labyrinth[x][y] = 1;
		}


		float nemoX, nemoY;
		cin >> nemoX >> nemoY;
		nemoX *= 2;
		nemoY *= 2;
		int nX = (int) nemoX;
		int nY = (int) nemoY;
		maxX = max(maxX, nX);
		maxY = max(maxY, nY);

		cout << nX << " " << nY << endl;
		cout << (nX * maxY) + nY << endl;

//		cout << distance[(nX * maxX) + nY] << endl;
		auto graph = makeGraph(labyrinth, maxX, maxY);
		auto distance = Dijkstra(graph, maxX, maxY);


		for(int i = 0; i < maxX; i++){
			for(int j = 0; j < maxY; j++){
				cout << arr[labyrinth[i][j]];
			}

			cout << endl;
		}

		cout << endl << endl;


		for(auto i : graph){
			cout << i.first << ": ";

			for(auto j : i.second){
				cout << "(" << j.first << ", " << j.second << ") ";
			}

			cout << endl;
		}


		if(distance[(nX * maxY) + nY] == 200000000){
			cout << "-1" << endl;
		}
		else{
			cout << distance[(nX * maxY) + nY] << endl;
		}

//		for(int i = 0; i < (int) distance.size(); i++){
//			cout << i << "; " << distance[i] << endl;
//		}
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int floodFill(vector<vector<char>>& farm, int i, int j){
	if(i < 0 || i >= (int) farm.size()){
		return 0;
	}
	if(j < 0 || j >= (int) farm.size()){
		return 0;
	}
	if(farm[i][j] == '*'){
		return 0;
	}

	int total = 0;

	if(farm[i][j] == 'C'){
		total++;
	}

	farm[i][j] = '*';

	for(int k = 0; k < 4; k++){
		total += floodFill(farm, i + dx[k], j + dy[k]);
	}

	return total;
}

int main() {
	int N, C;
	cin >> N >> C;

//	vector<vector<char>> farm (1000000, vector<char> (1000000, '.'));
	vector<pair<int, int>> positions;
	vector<vector<int>> coordinates;
	int maxCoordinate = 0;

	for(int i = 0; i < N; i++){
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;

		coordinates.push_back({X1, Y1, X2, Y2});
		maxCoordinate = max(maxCoordinate, max(max(X1, Y1), max(X2, Y2)));

//		for(int j = X1; j <= X2; j++){
//			for(int k = Y1; k <= Y2; k++){
//				farm[j][k] = '*';
//			}
//		}
	}

	for(int i = 0; i < C; i++){
		int X, Y;
		cin >> X >> Y;

		maxCoordinate = max(maxCoordinate, max(X, Y));
		positions.push_back(make_pair(X, Y));
	}

	vector<vector<char>> farm (maxCoordinate + 1, vector<char> (maxCoordinate + 1, '.'));
//	cout << maxCoordinate << endl;

	for(int i = 0; i < N; i++){
		for(int j = min(coordinates[i][0], coordinates[i][2]); j <= max(coordinates[i][0], coordinates[i][2]); j++){
			for(int k = min(coordinates[i][1], coordinates[i][3]); k <= max(coordinates[i][1], coordinates[i][3]); k++){
//				cout << i << " " << j << " " << k << endl;

				farm[j][k] = '*';
			}
		}

		cout << i << endl;

		for(int i = 0; i <= maxCoordinate; i++){
			for(int j = 0; j <= maxCoordinate; j++){
				cout << farm[i][j] << " ";
			}

			cout << endl;
		}

		cout << "...................." << endl;
	}

	for(int i = 0; i < C; i++){
		farm[positions[i].first][positions[i].second] = 'C';
	}

	for(int i = 0; i <= maxCoordinate; i++){
		for(int j = 0; j <= maxCoordinate; j++){
			cout << farm[i][j] << " ";
		}

		cout << endl;
	}

	int maximum = 0;

	for(auto i : positions){
		if(farm[i.first][i.second] == '*'){
			continue;
		}
		maximum = max(maximum, floodFill(farm, i.first, i.second));
	}

	cout << maximum << endl;

	return 0;
}

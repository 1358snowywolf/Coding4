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
	ifstream fin ("crazy.in");
	ofstream fout ("crazy.out");

	int N, C;
	cin >> N >> C;

	vector<pair<int, int>> positions;
	vector<vector<int>> coordinates;
	int maxX = 0, minX = 0, maxY = 0, minY = 0;

	for(int i = 0; i < N; i++){
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;

		coordinates.push_back({X1, Y1, X2, Y2});
		maxX = max(maxX, max(X1, X2));
		maxY = max(maxY, max(Y1, Y2));
		minY = min(minY, max(Y1, Y2));
		minX = min(maxX, max(X1, X2));
	}

	for(int i = 0; i < C; i++){
		int X, Y;
		cin >> X >> Y;

		positions.push_back(make_pair(X, Y));
		maxX = max(maxX, X);
		maxY = max(maxY, Y);
		minY = min(minY, Y);
		minX = min(maxX, X);
	}

	vector<vector<char>> farm (2 * (maxX - minX + 2), vector<char> (2 * (maxY - minY + 2), '.'));

	for(int i = 0; i < N; i++){
		for(int j = min(coordinates[i][0], coordinates[i][2]) * 2; j <= max(coordinates[i][0], coordinates[i][2]) * 2; j++){
			for(int k = min(coordinates[i][1], coordinates[i][3]) * 2; k <= max(coordinates[i][1], coordinates[i][3]) * 2; k++){
				farm[j][k] = '*';
			}
		}

//		cout << i << endl;
//
//		for(int i = 0; i <= maxCoordinate; i++){
//			for(int j = 0; j <= maxCoordinate; j++){
//				cout << farm[i][j] << " ";
//			}
//
//			cout << endl;
//		}
//
//		cout << "...................." << endl;
	}

	for(int i = 0; i < C; i++){
		farm[(positions[i].first * 2) - (minX * 2)][(positions[i].second * 2) - (minY * 2)] = 'C';
	}

//	for(int i = 0; i <= maxCoordinate; i++){
//		for(int j = 0; j <= maxCoordinate; j++){
//			cout << farm[i][j] << " ";
//		}
//
//		cout << endl;
//	}

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

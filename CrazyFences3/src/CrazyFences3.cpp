#include <bits/stdc++.h>

using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int Compression(int a[3010], int Z){
	int tmp[Z];
	memcpy(tmp, a, sizeof(tmp));
	sort(tmp, tmp + Z);
	int newZ = unique(tmp, tmp + Z) - tmp;

	for(int i = 0; i < Z; i++){
		a[i] = (lower_bound(tmp, tmp + newZ, a[i]) - tmp) * 2;
	}

	return newZ * 2;
}

int floodFill(vector<vector<char>>& farm, int i, int j){
	if(i < 0 || i >= (int) farm.size()){
		return 0;
	}
	if(j < 0 || j >= (int) farm[0].size()){
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
//	freopen("crazy.in", "r", stdin);
//	freopen("crazy.out", "w", stdout);
	int N, C;
	cin >> N >> C;
	int x[(N * 2) + C], y[(N * 2) + C];

	for(int i = 0; i < N; i++){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		x[i * 2] = x1;
		y[i * 2] = y1;
		x[(i * 2) + 1] = x2;
		y[(i * 2) + 1] = y2;
	}

	for(int i = 0; i < C; i++){
		int X, Y;
		cin >> X >> Y;
		x[(N * 2) + i] = X;
		y[(N * 2) + i] = Y;
	}

	int compressedX = Compression(x, (N * 2) + C);
	int compressedY = Compression(y, (N * 2) + C);

//	for(int i = 0; i < (N * 2) + C; i++){
//		cout << x[i] << ", " << y[i] << endl;
//	}

//	cout << endl;
//
//	for(int i = 0; i < (N * 2) + C; i++){
//		cout << y[i] << " ";
//	}

//	cout << endl;

	vector<vector<char>> farm (compressedX, vector<char> (compressedY, '.'));

	for(int i = 0; i < N * 2; i += 2){
		for(int j = min(x[i], x[i + 1]); j <= max(x[i], x[i + 1]); j++){
			for(int k = min(y[i], y[i + 1]); k <= max(y[i], y[i + 1]); k++){
				farm[j][k] = '*';
			}
		}

//		for(int j = 0; j < )
//		}

//		for(int i = 0; i < compressedX; i++){
//			for(int j = 0; j < compressedY; j++){
//				cout << farm[i][j] << " ";
//			}
//
//			cout << endl;
//		}
//
//		cout << endl << "//////////////////////////////////////////" << endl;
	}

	for(int i = 0; i < C; i++){  // insert C into graph
		farm[x[(N * 2) + i]][y[(N * 2) + i]] = 'C';
	}

	cout << endl;

	for(int i = 0; i < compressedX; i++){
		for(int j = 0; j < compressedY; j++){
			cout << farm[i][j] << " ";
		}

		cout << endl;
	}

	int maximum = 0;

	for(int i = N * 2; i < (N * 2) + C; i++){
		if(farm[x[i]][y[i]] == '*'){
			continue;
		}

		maximum = max(maximum, floodFill(farm, x[i], y[i]));


//		cout << endl;
//
//		for(int i = 0; i < compressedX; i++){
//			for(int j = 0; j < compressedY; j++){
//				cout << farm[i][j] << " ";
//			}
//
//			cout << endl;
//		}
	}

	cout << maximum << endl;

	return 0;
}

#include <bits/stdc++.h>

using namespace std;
vector<vector<bool>> field (10000, vector<bool> (10000, false));

void fill(int x1, int y1, int x2, int y2){
	for(int i = min(x1, x2); i < max(x1, x2); i++){
		for(int j = min(y1, y2); j < max(y1, y2); j++){
			field[j][i] = true;
		}
	}
}

int main() {
	int N;
	cin >> N;
	int minX = INT_MAX;
	int maxX = INT_MIN;
	int minY = INT_MAX;
	int maxY = INT_MIN;

	for(int i = 0; i < N; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		fill(x1, y1, x2, y2);
		minX = min(minX, min(x1, x2));
		maxX = max(maxX, max(x1, x2));
		minY = min(minY, min(y1, y2));
		maxY = max(maxY, max(y1, y2));
	}

	int total = 0;

	for(int i = minX; i <= maxX; i++){
		for(int j = minY; j <= maxY; j++){
			total += (field[j][i]) ? 1 : 0;
		}
	}

	cout << total << endl;

	return 0;
}

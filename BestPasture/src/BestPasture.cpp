#include <bits/stdc++.h>

using namespace std;

int main() {
	int P, F, C;
	cin >> P >> F >> C;
	vector<int> favorites;
	vector<vector<int>> FloydWarshall (P, vector<int> (P, 2000000));

	for(int i = 0; i < F; i++){
		int input;
		cin >> input;
		favorites.push_back(input - 1);
	}

//	sort(favorites.begin(), favorites.end());

	for(int i = 0; i < C; i++){
		int u, v, w;
		cin >> u >> v >> w;
		FloydWarshall[u - 1][v - 1] = w;
		FloydWarshall[v - 1][u - 1] = w;
	}

	for(int i = 0; i < P; i++){
		FloydWarshall[i][i] = 0;
	}

	for(int k = 0; k < P; k++){
		for(int i = 0; i < P; i++){
			for(int j = 0; j < P; j++){
				FloydWarshall[i][j] = min(FloydWarshall[i][j], FloydWarshall[i][k] + FloydWarshall[k][j]);
			}
		}
	}

//	for (int j = 0; j < F; j++) {
//		cout << favorites[j] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i< P; i ++) {
//		cout << i << " : ";
//		for (int j = 0; j < F; j++) {
//			cout << FloydWarshall[i][favorites[j]] << " ";
//		}
//		cout << endl;
//	}

	int minimum = INT_MAX;
	int pasture = 0;

	for(int i = 0; i < P; i++){
		int sum = 0;

		for(int j = 0; j < F; j++){
			sum += FloydWarshall[i][favorites[j]];
		}

//		cout << i << "  " << sum << endl;

		if(sum < minimum){
			pasture = i;
			minimum = sum;
		}
	}

	cout << pasture + 1 << endl;

	return 0;
}

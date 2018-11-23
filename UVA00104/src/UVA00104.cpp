#include <bits/stdc++.h>

using namespace std;

void findPath(vector<vector<int>> parents, vector<int>& path, int i, int j){
	if(i != j){
		findPath(parents, path, i, parents[i][j]);
	}

	cout << i << " " << j;
	path.push_back(j);
}

int main() {
	int N;
//	cout << endl;
	while(cin >> N){
		vector<vector<float>> table (N, vector<float> (N, 2000000));
		vector<vector<int>> parents (N, vector<int> (N, 2000000));

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(i == j){
					table[i][i] = 0;
				}
				else{
					float transaction;
					cin >> transaction;

					table[i][j] = transaction;
				}

				parents[i][j] = i;
			}
		}

//		for(int i = 0; i < N; i++){
//			for(int j = 0; j < N; j++){
//				cout << table[i][j] << " ";
//			}
//
//			cout << endl;
//		}

		for(int k = 0; k < N; k++){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					if(table[i][k] * table[k][j] > table[i][j]){
						table[i][j] = table[i][k] * table[k][j];
						parents[i][j] = parents[k][j];
					}
				}
			}
		}


//		for(int i = 0; i < N; i++){
//			for(int j = 0; j < N; j++){
//				cout << table[i][j] << " ";
//			}
//
//			cout << endl;
//		}

		vector<int> path;
		float maximum = 0;

		for(int i = 0; i < N; i++){
//			for(int j = 0; j < N; j++){
//				if(table[i][j] > maximum){
//					path.clear();
//					maximum = table[i][j];
//					findPath(parents, path, i, j);
//				}
//			}

			if(table[i][i] > maximum){
				path.clear();
				maximum = table[i][i];
				findPath(parents, path, i, i);
			}
		}

		if(maximum <= 1 && (int) path.size() < N){
			cout << "no arbitrage sequence exists" << endl;
		}
		else{
			for(int i = 0; i < (int) path.size() - 1; i++){
				cout << path[i] << " ";
			}

			cout << path[path.size() - 1] << endl;
		}

//		break;
	}

	return 0;
}

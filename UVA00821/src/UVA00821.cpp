#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, M;
	int index = 1;

	while(cin >> N >> M){
		if(N == 0 && M == 0){
			break;
		}

		int maximum = max(N, M);
		vector<pair<int, int>> connections;
		connections.push_back(make_pair(N - 1, M - 1));

		while(N != 0 && M != 0){
			cin >> N >> M;
			maximum = max(maximum, max(N, M));
			connections.push_back(make_pair(N - 1, M - 1));
		}

		vector<vector<int>> weights (maximum, vector<int> (maximum, 2000000));

		for(int i = 0; i < (int) connections.size() - 1; i++){
			weights[connections[i].first][connections[i].second] = 1;
		}

		for(int i = 0; i < maximum; i++){
			weights[i][i] = 0;
		}

		for(int k = 0; k < maximum; k++){
			for(int i = 0; i < maximum; i++){
				for(int j = 0; j < maximum; j++){
					weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);
				}
			}
		}

		int sum = 0;
		int reach = 0;

		for(int i = 0; i < maximum; i++){
			for(int j = 0; j < maximum; j++){
				if(weights[i][j] != 2000000 && weights[i][j] != 0){
					sum += weights[i][j];
					reach++;
				}
			}
		}

		float average = (float) sum / (float) reach;

		cout << "Case " << index << ": " << "average length between pages = " << fixed << setprecision(3) << average << " clicks" << endl;

		index++;
	}


	return 0;
}

#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> big, small;
int N, n;

void rotate(){
	vector<vector<char>> answer (n, vector<char> (n, '.'));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			answer[j][i] = small[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		reverse(answer[i].begin(), answer[i].end());
	}

	small = answer;
}

bool check(int i, int j){
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			if(big[x + i][y + j] != small[x][y]){
				return false;
			}
		}
	}

	return true;
}

int main() {
	string line;
	vector<char> input;

	while(true){
		big.clear();
		small.clear();
		cin >> N >> n;
//		cout << endl;

		if(N == 0 && n == 0){
			break;
		}

		for(int i = 0; i < N; i++){
			cin >> line;
			input.clear();
			for(int j = 0; j < N; j++){
				input.push_back(line[j]);
			}
			big.push_back(input);
		}

		for(int i = 0; i < n; i++){
			cin >> line;
			input.clear();
			for(int j = 0; j < n; j++){
				input.push_back(line[j]);
			}
			small.push_back(input);
		}

		vector<int> answer (4, 0);

		for(int k = 0; k < 4; k++){
			int total = 0;

			for(int i = 0; i <= N - n; i++){
				for(int j = 0; j <= N - n; j++){
					if(check(i, j)){
						total++;
//						cout << i << " " << j << " " << total << endl;
					}
				}
			}

			answer[k] = total;
//			cout << total << " ";

//			for(int i = 0; i < n; i++){
//				for(int j = 0; j < n; j++){
//					cout << small[i][j] << " ";
//				}
//				cout << endl;
//			}
//			cout << "........." << endl;

			rotate();

		}

//		cout << endl;

		for(int i = 0; i < 3; i++){
			cout << answer[i] << " ";
		}

		cout << answer[3] << endl;
	}

	return 0;
}
